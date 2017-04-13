//
// Map.cpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/src/src_pacman/src/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Thu Apr 13 10:06:09 2017 Melvin Personnier
// Last update Thu Apr 13 20:02:28 2017 Melvin Personnier
//

#include "Map.hpp"

Map::Map(int width, int height)
    : _width(width), _height(height)
{
  std::srand(std::time(0));
  _map = new Info*[_height];
  for(int i = 0; i < _height; ++i)
      _map[i] = new Info[_width];
  init();
}

Map::~Map()
{
	for (int i = 0; i < _height; i++)
		delete _map[i];
	delete _map;
}

void Map::init()
{
  for (int i = 0; i < _height; i++)
    for (int j = 0; j < _width; j++)
    {
      if (i == 0 || j == 0 || i == _height - 1 || j == _width - 1)
        _map[i][j] = BLOCK;
      else
        _map[i][j] = POWERUP;
      if (i > 8 && i < 20 && j > 6 && j < 21)
        _map[i][j] = EMPTY;
    }
  generateIsland(2, 2, 4, 3); // 1
  generateIsland(7, 2, 5, 3); // 2
  generateIsland(13, 1, 2, 4); // 3
  generateIsland(16, 2, 5, 3); // 4
  generateIsland(22, 2, 4, 3); // 5
  generateIsland(2, 6, 4, 2); // 6
  generateIsland(7, 6, 2, 8); // 7
  generateIsland(9, 9, 3, 2); // 8
  generateIsland(10, 6, 8, 2); // 9
  generateIsland(13, 8, 2, 3); // 10
  generateIsland(16, 9, 3, 2); // 11
  generateIsland(19, 6, 2, 8); // 12
  generateIsland(22, 6, 4, 2); // 13a
  generateIsland(7, 15, 2, 5); // 13
  generateIsland(19, 15, 2, 5); // 14
  generateIsland(10, 18, 8, 2); // 15
  generateIsland(13, 20, 2, 3); // 16
  generateIsland(2, 21, 4, 2); // 17
  generateIsland(4, 23, 2, 3); // 18
  generateIsland(7, 21, 5, 2); // 19
  generateIsland(16, 21, 5, 2); // 20
  generateIsland(22, 21, 4, 2); // 21
  generateIsland(22, 23, 2, 3); // 22
  generateIsland(1, 24, 2, 2); // 23
  generateIsland(7, 24, 2, 3); // 24
  generateIsland(2, 27, 10, 2); // 25
  generateIsland(10, 24, 8, 2); // 26
  generateIsland(13, 26, 2, 3); // 27
  generateIsland(19, 24, 4, 2); // 28
  generateIsland(16, 27, 10, 2); // 29
  generateIsland(25, 24, 2, 2); // 30
  generateIsland(1, 9, 5, 5); // hg
  generateIsland(1, 15, 5, 5); // bg
  generateIsland(22, 9, 5, 5); // hd
  generateIsland(22, 15, 5, 5); // bd
  generateIsland(10, 12, 8, 1); // h
  generateIsland(10, 16, 8, 1); // b
  generateIsland(10, 12, 1, 5); // g
  generateIsland(17, 12, 1, 5); // d
  _map[12][13] = _map[12][14] = Map::DOOR;
}

int Map::getHeight() const
{
	return _height;
}

int Map::getWidth() const
{
	return _width;
}

void Map::generateIsland(int posX, int posY, int largeur, int longueur)
{
  for (int i = posY; i < longueur + posY; i++)
    for (int j = posX; j < largeur + posX; j++)
      _map[i][j] = Map::BLOCK;
}

Map::Info Map::getCaseInfo(int width, int height)
{
  if (width >= 0 && height >= 0 && width < _width && height < _height)
    return _map[height][width];
  return Map::ERROR;
}

void Map::setCaseInfo(int width, int height, Map::Info info)
{
  if (width >= 0 && height >= 0 && width < _width && height < _height)
    _map[height][width] = info;
}
