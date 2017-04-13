//
// Pacman.cpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/src/src_pacman/src/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Thu Apr 13 09:49:51 2017 Melvin Personnier
// Last update Thu Apr 13 22:21:16 2017 Melvin Personnier
//

#include "Pacman.hpp"

Pacman::Pacman(int width, int height)
{
  if (width != 27 || height != 31)
    throw MapToSmall("Map's width must be == 28 && Map's height == 31");
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
      this->getWhereAmI()->position[0].y - 1 == Map::Info::EMPTY) ||
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
      this->getWhereAmI()->position[0].y - 1 == Map::Info::POWERUP))
    {
      this->getWhereAmI()->position[0].y--;
      this->getMap()->setCaseInfo(this->getWhereAmI()->position[0].x,
          this->getWhereAmI()->position[0].y, Map::Info::EMPTY);
      _dir = Direction::UP;
    }
}

void Pacman::goDown()
{
  if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
      this->getWhereAmI()->position[0].y + 1 == Map::Info::EMPTY) ||
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
      this->getWhereAmI()->position[0].y + 1 == Map::Info::POWERUP))
    {
      this->getWhereAmI()->position[0].y++;
      this->getMap()->setCaseInfo(this->getWhereAmI()->position[0].x,
          this->getWhereAmI()->position[0].y, Map::Info::EMPTY);
      _dir = Direction::DOWN;
    }
}

void Pacman::goLeft()
{
  if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x - 1,
      this->getWhereAmI()->position[0].y == Map::Info::EMPTY) ||
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x - 1,
      this->getWhereAmI()->position[0].y == Map::Info::POWERUP))
    {
      this->getWhereAmI()->position[0].x--;
      this->getMap()->setCaseInfo(this->getWhereAmI()->position[0].x,
          this->getWhereAmI()->position[0].y, Map::Info::EMPTY);
      _dir = Direction::LEFT;
    }
}

void Pacman::goRight()
{
  if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x + 1,
      this->getWhereAmI()->position[0].y == Map::Info::EMPTY) ||
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x + 1,
      this->getWhereAmI()->position[0].y == Map::Info::POWERUP))
    {
      this->getWhereAmI()->position[0].x++;
      this->getMap()->setCaseInfo(this->getWhereAmI()->position[0].x,
          this->getWhereAmI()->position[0].y, Map::Info::EMPTY);
      _dir = Direction::RIGHT;
    }
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
}
