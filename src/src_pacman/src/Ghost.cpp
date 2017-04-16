//
// Ghost.cpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/src/src_pacman/src/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Fri Apr 14 17:58:33 2017 Melvin Personnier
// Last update Sun Apr 16 02:11:36 2017 Melvin Personnier
//

#include "Ghost.hpp"

Ghost::Ghost(int width, int height, Map *map)
{
  int sizeOfStruct = sizeof(struct arcade::WhereAmI) +
	      sizeof(arcade::Position);
  _whereAmI = reinterpret_cast<struct arcade::WhereAmI *>
        (new char[sizeOfStruct]);
  _whereAmI->lenght = 1;
  _whereAmI->position[0].x = width;
  _whereAmI->position[0].y = height;
  _dir = Direction::DOWN;
  _map = map;
  _outOfBlock = false;
}

Ghost::~Ghost()
{
}

Map *Ghost::getMap() const
{
  return _map;
}

arcade::WhereAmI *Ghost::getWhereAmI() const
{
  return _whereAmI;
}

Ghost::Direction Ghost::getDir() const
{
  return _dir;
}

void Ghost::setDir(Direction dir)
{
  _dir = dir;
}

bool Ghost::getOutOfBlock()
{
  return _outOfBlock;
}

void Ghost::setOutOfBlock()
{
  _outOfBlock = true;
}

bool Ghost::goUp()
{
  if (_dir == Direction::DOWN)
    return false;
  if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
          this->getWhereAmI()->position[0].y - 1) == Map::Info::EMPTY ||
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
          this->getWhereAmI()->position[0].y - 1) == Map::Info::POWERUP ||
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
          this->getWhereAmI()->position[0].y - 1) == Map::Info::SUPERPOWERUP)
    {
      this->getWhereAmI()->position[0].y--;
      _dir = Direction::UP;
      return true;
    }
  return false;

}

bool Ghost::goDown()
{
  if (_dir == Direction::UP)
    return false;
  if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
          this->getWhereAmI()->position[0].y + 1) == Map::Info::EMPTY ||
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
          this->getWhereAmI()->position[0].y + 1) == Map::Info::POWERUP ||
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
          this->getWhereAmI()->position[0].y + 1) == Map::Info::SUPERPOWERUP)
    {
      this->getWhereAmI()->position[0].y++;
      _dir = Direction::DOWN;
      return true;
    }
    return false;
}

bool Ghost::goLeft()
{
  if (_dir == Direction::RIGHT)
    return false;
  if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x - 1,
          this->getWhereAmI()->position[0].y) == Map::Info::EMPTY ||
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x - 1,
          this->getWhereAmI()->position[0].y) == Map::Info::POWERUP ||
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x - 1,
          this->getWhereAmI()->position[0].y) == Map::Info::SUPERPOWERUP)
    {
      this->getWhereAmI()->position[0].x--;
      _dir = Direction::LEFT;
      return true;
    }
    return false;
}

bool Ghost::goRight()
{
  if (_dir == Direction::LEFT)
    return false;
  if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x + 1,
          this->getWhereAmI()->position[0].y) == Map::Info::EMPTY ||
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x + 1,
          this->getWhereAmI()->position[0].y) == Map::Info::POWERUP ||
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x + 1,
          this->getWhereAmI()->position[0].y) == Map::Info::SUPERPOWERUP)
    {
      this->getWhereAmI()->position[0].x++;
      _dir = Direction::RIGHT;
      return true;
    }
    return false;
}

void Ghost::chooseDir()
{
  int myRand;
  bool a;

  myRand = std::rand() % 4;
  if (myRand == 0)
    a = this->goUp();
  if (myRand == 1)
    a = this->goDown();
  if (myRand == 2)
    a = this->goRight();
  if (myRand == 3)
    a = this->goLeft();
  if (a == false)
    this->chooseDir();
}


void Ghost::goPlay()
{
  bool a = false;
  if (_dir == Direction::UP)
    a = this->goUp();
  else if (_dir == Direction::DOWN)
    a = this->goDown();
  else if (_dir == Direction::LEFT)
    a = this->goLeft();
  else if (_dir == Direction::RIGHT)
    a = this->goRight();
  if (a == false)
    this->chooseDir();



}
