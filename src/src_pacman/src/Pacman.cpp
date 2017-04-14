//
// Pacman.cpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/src/src_pacman/src/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Thu Apr 13 09:49:51 2017 Melvin Personnier
// Last update Fri Apr 14 17:14:03 2017 Melvin Personnier
//

#include "Pacman.hpp"

Pacman::Pacman(int width, int height)
{

  int sizeOfStruct = sizeof(struct arcade::WhereAmI) +
	      sizeof(arcade::Position);
  _map = new Map(width, height);
  _whereAmI = reinterpret_cast<struct arcade::WhereAmI *>
	      (new char[sizeOfStruct]);
  _whereAmI->lenght = 1;
  _whereAmI->position[0].x = 13;
  _whereAmI->position[0].y = 23;
  _gameOver = false;
  _dir = Direction::LEFT;
  _screen.width = MAP_W;
  _screen.height = MAP_H;
  _speed = 150000;
}

Pacman::~Pacman()
{
  delete _map;
}

Map *Pacman::getMap() const
{
  return _map;
}

arcade::WhereAmI *Pacman::getWhereAmI() const
{
  return _whereAmI;
}

Pacman::Direction Pacman::getDir() const
{
  return _dir;
}

void Pacman::setDir(Direction dir)
{
  _dir = dir;
}

void Pacman::goUp()
{
  if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
				  this->getWhereAmI()->position[0].y - 1) == Map::Info::EMPTY ||
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
				  this->getWhereAmI()->position[0].y - 1) == Map::Info::POWERUP)
    {
      this->getWhereAmI()->position[0].y--;
      this->getMap()->setCaseInfo(this->getWhereAmI()->position[0].x,
          this->getWhereAmI()->position[0].y, Map::Info::EMPTY);
      _lastDir = Direction::UP;
    }
    else _dir = _lastDir;
}

void Pacman::goDown()
{
  if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
				  this->getWhereAmI()->position[0].y + 1) == Map::Info::EMPTY ||
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
				  this->getWhereAmI()->position[0].y + 1) == Map::Info::POWERUP)
    {
      this->getWhereAmI()->position[0].y++;
      this->getMap()->setCaseInfo(this->getWhereAmI()->position[0].x,
          this->getWhereAmI()->position[0].y, Map::Info::EMPTY);
      _lastDir = Direction::DOWN;
    }
    else _dir = _lastDir;
}

void Pacman::goLeft()
{
  if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x - 1,
				  this->getWhereAmI()->position[0].y) == Map::Info::EMPTY ||
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x - 1,
				  this->getWhereAmI()->position[0].y) == Map::Info::POWERUP)
    {
      this->getWhereAmI()->position[0].x--;
      this->getMap()->setCaseInfo(this->getWhereAmI()->position[0].x,
          this->getWhereAmI()->position[0].y, Map::Info::EMPTY);
      _lastDir = Direction::LEFT;
    }
    else _dir = _lastDir;
}

void Pacman::goRight()
{
  if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x + 1,
				  this->getWhereAmI()->position[0].y) == Map::Info::EMPTY ||
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x + 1,
				  this->getWhereAmI()->position[0].y) == Map::Info::POWERUP)
    {
      this->getWhereAmI()->position[0].x++;
      this->getMap()->setCaseInfo(this->getWhereAmI()->position[0].x,
          this->getWhereAmI()->position[0].y, Map::Info::EMPTY);
      _lastDir = Direction::RIGHT;
    }
    else _dir = _lastDir;
}

void Pacman::goPlay()
{
  if (_dir == Direction::UP)
    this->goUp();
  else if (_dir == Direction::DOWN)
    this->goDown();
  else if (_dir == Direction::LEFT)
    this->goLeft();
  else if (_dir == Direction::RIGHT)
    this->goRight();
  updateTiles();
}

void Pacman::updateTiles()
{
  int	i;
  int	x;
  int	y;
  TileInfo tile;
  Pixel pixel;

  i = 0;
  x = 0;
  y = 0;
  tile.filePath = NULL;
  tile.spriteIndex = 0;
  _tiles.erase(_tiles.begin(), _tiles.end());
  while (i < MAP_W * MAP_H)
    {
      if (x == MAP_W)
      	{
      	  x = 0;
      	  y += 1;
      	}
      if (_whereAmI->position[0].x == x && _whereAmI->position[0].y == y)
      	pixel.hexacode = 0xffffff;
      else if (_map->getCaseInfo(x, y) == Map::Info::BLOCK)
      	pixel.hexacode = 0xff0000;
      else if (_map->getCaseInfo(x, y) == Map::Info::EMPTY)
      	pixel.hexacode = 0x000000;
      else if (_map->getCaseInfo(x, y) == Map::Info::POWERUP)
      	pixel.hexacode = 0x0000ff;
      tile.color = pixel;
      _tiles.push_back(tile);
      x++;
      i++;
    }
}

std::vector<TileInfo> const &Pacman::getTiles() const
{
  return _tiles;
}

struct_info Pacman::runCommand(arcade::CommandType type)
{
  struct_info null;

  if (type == arcade::CommandType::GO_UP)
    setDir(Pacman::Direction::UP);
  else if (type  == arcade::CommandType::GO_DOWN)
    setDir(Pacman::Direction::DOWN);
  else if (type == arcade::CommandType::GO_LEFT)
    setDir(Pacman::Direction::LEFT);
  else if (type == arcade::CommandType::GO_RIGHT)
    setDir(Pacman::Direction::RIGHT);
  else if (type == arcade::CommandType::PLAY)
    goPlay();
  return (null);
}

Screen const &Pacman::getScreen() const
{
  return (_screen);
}

int const &Pacman::getSpeed() const
{
  return (_speed);
}

ILogic *cln::clone()
{
  return new Pacman(MAP_W, MAP_H);
}
