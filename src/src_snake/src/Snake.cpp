//
// Snake.cpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/src/src_snake/src/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Tue Apr 11 17:18:54 2017 Melvin Personnier
// Last update Thu Apr 13 19:55:56 2017 Melvin Personnier
//

#include "Snake.hpp"

Snake::Snake(int width, int height)
{
  if (width < 8 || height < 8)
    throw MapToSmall("Map's width and height must be >= 7");
  int sizeOfStruct = sizeof(struct arcade::WhereAmI) +
    sizeof(arcade::Position) * width * height;
	_map = new Map(width, height);
  _whereAmI = reinterpret_cast<struct arcade::WhereAmI *>
         (new char[sizeOfStruct]);
  _whereAmI->lenght = 4;
  for (size_t i = 0; i < 4; i++) {
    _whereAmI->position[i].x = _map->getWidth() / 2 - 2 + i;
    _whereAmI->position[i].y = _map->getHeight() / 2;
  }
  _gameOver = false;
  _powerUp = false;
  //_map->setCaseInfo(3, 5, Map::POWERUP);
  _map->setPowerUp();
  _dir = Direction::UP;
}

Snake::~Snake()
{
	delete _map;
}

Map *Snake::getMap() const
{
	return _map;
}

arcade::WhereAmI *Snake::getWhereAmI() const
{
	return _whereAmI;
}

Snake::Direction Snake::getDir() const
{
  return _dir;
}

void Snake::setDir(Direction dir)
{
  _dir = dir;
}


void Snake::goUp()
{
  int lenght = this->getWhereAmI()->lenght;
  if (_dir == Direction::DOWN)
    return ;
  if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
      this->getWhereAmI()->position[0].y - 1 != Map::Info::EMPTY) &&
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
      this->getWhereAmI()->position[0].y - 1 != Map::Info::POWERUP))
    {
      _gameOver = true;
    }
  else {
    if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
        this->getWhereAmI()->position[0].y - 1) == Map::POWERUP) {
        _powerUp = true;
        this->getMap()->setCaseInfo(this->getWhereAmI()->position[0].x, this->getWhereAmI()->position[0].y - 1, Map::EMPTY);
      }
    if (_powerUp == true) {
          this->getWhereAmI()->position[lenght + 1].y = this->getWhereAmI()->position[lenght].y;
          this->getWhereAmI()->position[lenght + 1].x = this->getWhereAmI()->position[lenght].x;
          this->getWhereAmI()->lenght +=1;
    }
    for (int i = lenght; i > 0; i--) {
      this->getWhereAmI()->position[i].y = this->getWhereAmI()->position[i - 1].y;
      this->getWhereAmI()->position[i].x = this->getWhereAmI()->position[i - 1].x;
    }
    this->getWhereAmI()->position[0].y = this->getWhereAmI()->position[1].y - 1;
    this->getWhereAmI()->position[0].x = this->getWhereAmI()->position[1].x;
    if (_powerUp == true) {
      _powerUp = false;
      _map->setPowerUp();
    }
  }
  _dir = Direction::UP;
}

void Snake::goDown()
{
  int lenght = this->getWhereAmI()->lenght;
  if (_dir == Direction::UP)
    return ;
  if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
      this->getWhereAmI()->position[0].y + 1 != Map::Info::EMPTY) &&
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
      this->getWhereAmI()->position[0].y + 1 != Map::Info::POWERUP))
    {
      _gameOver = true;
    }
  else {
    if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
        this->getWhereAmI()->position[0].y + 1) == Map::Info::POWERUP) {
        _powerUp = true;
        this->getMap()->setCaseInfo(this->getWhereAmI()->position[0].x, this->getWhereAmI()->position[0].y + 1, Map::EMPTY);
      }
    if (_powerUp == true) {
        this->getWhereAmI()->position[lenght + 1].y = this->getWhereAmI()->position[lenght].y;
        this->getWhereAmI()->position[lenght + 1].x = this->getWhereAmI()->position[lenght].x;
        this->getWhereAmI()->lenght +=1;
    }
    for (int i = lenght; i > 0; i--) {
      this->getWhereAmI()->position[i].y = this->getWhereAmI()->position[i - 1].y;
      this->getWhereAmI()->position[i].x = this->getWhereAmI()->position[i - 1].x;
    }
    this->getWhereAmI()->position[0].y = this->getWhereAmI()->position[1].y + 1;
    this->getWhereAmI()->position[0].x = this->getWhereAmI()->position[1].x;
    if (_powerUp == true) {
      _powerUp = false;
      _map->setPowerUp();
    }
  }
  _dir = Direction::DOWN;
}

void Snake::goLeft()
{
  int lenght = this->getWhereAmI()->lenght;
  if (_dir == Direction::RIGHT)
    return ;
  if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x - 1,
      this->getWhereAmI()->position[0].y != Map::Info::EMPTY) &&
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x - 1,
      this->getWhereAmI()->position[0].y != Map::Info::POWERUP))
    {
      _gameOver = true;
    }
  else {
    if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x - 1,
        this->getWhereAmI()->position[0].y) == Map::Info::POWERUP) {
        _powerUp = true;
        this->getMap()->setCaseInfo(this->getWhereAmI()->position[0].x - 1, this->getWhereAmI()->position[0].y, Map::EMPTY);
      }
    if (_powerUp == true) {
        this->getWhereAmI()->position[lenght + 1].y = this->getWhereAmI()->position[lenght].y;
        this->getWhereAmI()->position[lenght + 1].x = this->getWhereAmI()->position[lenght].x;
        this->getWhereAmI()->lenght +=1;
    }
    for (int i = lenght; i > 0; i--) {
      this->getWhereAmI()->position[i].x = this->getWhereAmI()->position[i - 1].x;
      this->getWhereAmI()->position[i].y = this->getWhereAmI()->position[i - 1].y;
    }
    this->getWhereAmI()->position[0].x = this->getWhereAmI()->position[1].x - 1;
    this->getWhereAmI()->position[0].y = this->getWhereAmI()->position[1].y;
    if (_powerUp == true) {
      _powerUp = false;
      _map->setPowerUp();
    }
  }
  _dir = Direction::LEFT;
}

void Snake::goRight()
{
  int lenght = this->getWhereAmI()->lenght;
  if (_dir == Direction::LEFT)
    return ;
  if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x + 1,
      this->getWhereAmI()->position[0].y != Map::Info::EMPTY) &&
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x + 1,
      this->getWhereAmI()->position[0].y != Map::Info::POWERUP))
    {
      _gameOver = true;
    }
  else {
    if (this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x + 1,
        this->getWhereAmI()->position[0].y) == Map::Info::POWERUP) {
        _powerUp = true;
        this->getMap()->setCaseInfo(this->getWhereAmI()->position[0].x + 1, this->getWhereAmI()->position[0].y, Map::EMPTY);
      }
    if (_powerUp == true) {
        this->getWhereAmI()->position[lenght + 1].y = this->getWhereAmI()->position[lenght].y;
        this->getWhereAmI()->position[lenght + 1].x = this->getWhereAmI()->position[lenght].x;
        this->getWhereAmI()->lenght +=1;
    }
    for (int i = lenght; i > 0; i--) {
      this->getWhereAmI()->position[i].x = this->getWhereAmI()->position[i - 1].x;
      this->getWhereAmI()->position[i].y = this->getWhereAmI()->position[i - 1].y;
    }
    this->getWhereAmI()->position[0].x = this->getWhereAmI()->position[1].x + 1;
    this->getWhereAmI()->position[0].y = this->getWhereAmI()->position[1].y;
    if (_powerUp == true) {
      _powerUp = false;
      _map->setPowerUp();
    }
  }
  _dir = Direction::RIGHT;
}

void Snake::goPlay()
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
