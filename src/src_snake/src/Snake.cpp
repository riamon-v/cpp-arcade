//
// Snake.cpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/src/src_snake/src/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Tue Apr 11 17:18:54 2017 Melvin Personnier
// Last update Fri Apr 14 00:23:28 2017 Riamon Vincent
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
  _map->setPowerUp();
  _dir = Direction::UP;
  _screen.width = MAP_W;
  _screen.height = MAP_H;
  _speed = 80000;
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
				  this->getWhereAmI()->position[0].y - 1) != Map::Info::EMPTY &&
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
				  this->getWhereAmI()->position[0].y - 1)!= Map::Info::POWERUP)
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
				  this->getWhereAmI()->position[0].y + 1)!= Map::Info::EMPTY  &&
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x,
				  this->getWhereAmI()->position[0].y + 1)!= Map::Info::POWERUP)
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
				  this->getWhereAmI()->position[0].y) != Map::Info::EMPTY  &&
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x - 1,
				  this->getWhereAmI()->position[0].y) != Map::Info::POWERUP)
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
				  this->getWhereAmI()->position[0].y) != Map::Info::EMPTY &&
      this->getMap()->getCaseInfo(this->getWhereAmI()->position[0].x + 1,
				  this->getWhereAmI()->position[0].y) != Map::Info::POWERUP)
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
  updateTiles();
}

int Snake::is_in_list(int x, int y) const
{
  int i;

  i = -1;
  while (++i < _whereAmI->lenght)
    {
      if (_whereAmI->position[i].x == x && _whereAmI->position[i].y == y)
	return (1);
    }
  return (0);
}

void Snake::updateTiles()
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
      if (is_in_list(x, y))
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

std::vector<TileInfo> const &Snake::getTiles() const
{
  return _tiles;
}

struct_info Snake::runCommand(arcade::CommandType type)
{
  struct_info null;

  if (type == arcade::CommandType::GO_UP)
    setDir(Snake::Direction::UP);
  else if (type  == arcade::CommandType::GO_DOWN)
    setDir(Snake::Direction::DOWN);
  else if (type == arcade::CommandType::GO_LEFT)
    setDir(Snake::Direction::LEFT);
  else if (type == arcade::CommandType::GO_RIGHT)
    setDir(Snake::Direction::RIGHT);
  else if (type == arcade::CommandType::PLAY)
    goPlay();
  return (null);
}

Screen const &Snake::getScreen() const
{
  return (_screen);
}

int const &Snake::getSpeed() const
{
  return (_speed);
}

ILogic *cln::clone()
{
  return new Snake(MAP_W, MAP_H);
}
