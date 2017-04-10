//
// Map.cpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/src/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Sun Apr  9 21:29:22 2017 Melvin Personnier
// Last update Mon Apr 10 22:13:03 2017 Melvin Personnier
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
        _map[i][j] = EMPTY;
    }
}

int Map::getHeight() const
{
	return _height;
}

int Map::getWidth() const
{
	return _width;
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

void Map::setPowerUp()
{
  int y = std::rand() % _width;
  int x = std::rand() % _height;

  while (getCaseInfo(y, x) != Map::EMPTY) {
    y = std::rand() % _width;
    x = std::rand() % _height;
  }
  setCaseInfo(y, x, Map::POWERUP);
}
