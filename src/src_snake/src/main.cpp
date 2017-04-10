//
// main.cpp for main in /home/riamon_v/rendu/CPP/cpp_arcade/src/src_pacman
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Fri Apr  7 16:29:42 2017 Riamon Vincent
// Last update Tue Apr 11 00:38:26 2017 Melvin Personnier
//

#include "Snake.hpp"
#include "Protocol.hpp"

void MapToGetMap(arcade::CommandType cmd, Snake *snake)
{
  int sizeOfStruct = sizeof(struct arcade::GetMap) +
    sizeof(arcade::TileType) * (snake->getMap()->getWidth() * snake->getMap()->getHeight());

  int caseToUpdate;

  // Alloue la structure sizeof(char) * sizeOfStruct
  arcade::GetMap *getMap = reinterpret_cast<struct arcade::GetMap*>
    (new char[sizeOfStruct]);

  int height = 0;
  int width = 0;

  getMap->type = cmd;
  getMap->height = snake->getMap()->getHeight();
  getMap->width = snake->getMap()->getWidth();

  while (height < snake->getMap()->getHeight())
  {
      width = 0;
      while (width < snake->getMap()->getWidth())
      {
        caseToUpdate = height * snake->getMap()->getHeight() + width;
        if (snake->getMap()->getCaseInfo(width, height) == Map::Info::EMPTY)
    			getMap->tile[caseToUpdate] = arcade::TileType::EMPTY;
    		else if (snake->getMap()->getCaseInfo(width, height) == Map::Info::BLOCK)
    			getMap->tile[caseToUpdate] = arcade::TileType::BLOCK;
    		else if (snake->getMap()->getCaseInfo(width, height) == Map::Info::PLAYER)
    			getMap->tile[caseToUpdate] = arcade::TileType::EMPTY;
    		else if (snake->getMap()->getCaseInfo(width, height) == Map::Info::POWERUP)
    			getMap->tile[caseToUpdate] = arcade::TileType::POWERUP;
        ++width;
      }
      ++height;
    }
  	write(1, getMap, sizeOfStruct);

}

extern "C"  void		Play(void)
{
  arcade::CommandType cmd;
  Snake *snake;
  snake = new Snake(30, 30);

  while (read(0, &cmd, sizeof(arcade::CommandType)))
  {
    if (cmd == arcade::CommandType::WHERE_AM_I)
      std::cout << "where" << std::endl;
    else if (cmd == arcade::CommandType::GET_MAP)
      MapToGetMap(cmd, snake);
    else if (cmd == arcade::CommandType::GO_UP)
      std::cout << "up" << std::endl;
    else if (cmd == arcade::CommandType::GO_DOWN)
      std::cout << "down" << std::endl;
    else if (cmd == arcade::CommandType::GO_LEFT)
      std::cout << "left" << std::endl;
    else if (cmd == arcade::CommandType::GO_RIGHT)
      std::cout << "right" << std::endl;
    else if (cmd == arcade::CommandType::GO_FORWARD)
      std::cout << "forward" << std::endl;
    else if (cmd == arcade::CommandType::PLAY)
      std::cout << "play" << std::endl;
    }
}
