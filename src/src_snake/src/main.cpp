//
// main.cpp for main in /home/riamon_v/rendu/CPP/cpp_arcade/src/src_pacman
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Fri Apr  7 16:29:42 2017 Riamon Vincent
// Last update Tue Apr 11 01:09:56 2017 Melvin Personnier
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
  arcade::CommandType command;
  Snake *snake;
  snake = new Snake(30, 30);

  while (std::cin)
  {
    std::cin.read(reinterpret_cast<char *>(&command), sizeof(arcade::CommandType));
    if (command == arcade::CommandType::WHERE_AM_I)
      std::cout << "where" << std::endl;
    else if (command == arcade::CommandType::GET_MAP)
      MapToGetMap(command, snake);
    else if (command == arcade::CommandType::GO_UP)
      std::cout << "up" << std::endl;
    else if (command == arcade::CommandType::GO_DOWN)
      std::cout << "down" << std::endl;
    else if (command == arcade::CommandType::GO_LEFT)
      std::cout << "left" << std::endl;
    else if (command == arcade::CommandType::GO_RIGHT)
      std::cout << "right" << std::endl;
    else if (command == arcade::CommandType::GO_FORWARD)
      std::cout << "forward" << std::endl;
    else if (command == arcade::CommandType::PLAY)
      std::cout << "play" << std::endl;
    }
}
