//
// main.cpp for main in /home/riamon_v/rendu/CPP/cpp_arcade/src/src_pacman
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Fri Apr  7 16:29:42 2017 Riamon Vincent
// Last update Wed Apr 12 16:26:03 2017 Melvin Personnier
//

#include "SnakeGame.hpp"
#include "Snake.hpp"
#include "Protocol.hpp"

void getWhereAmI(arcade::CommandType command, Snake *snake)
{
  snake->getWhereAmI()->type = command;
  std::cout.write(reinterpret_cast<char *>(snake->getWhereAmI()), sizeof(struct arcade::WhereAmI) +
    sizeof(arcade::Position) * snake->getWhereAmI()->lenght);
}

void getMapToGetMap(arcade::CommandType command, Snake *snake)
{
  int sizeOfStruct = sizeof(struct arcade::GetMap) +
    sizeof(arcade::TileType) * (snake->getMap()->getWidth() * snake->getMap()->getHeight());

  int caseToUpdate;

  // Alloue la structure sizeof(char) * sizeOfStruct
  arcade::GetMap *getMap = reinterpret_cast<struct arcade::GetMap*>
    (new char[sizeOfStruct]);

  int height = 0;
  int width = 0;

  getMap->type = command;
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
    		else if (snake->getMap()->getCaseInfo(width, height) == Map::Info::SNAKE)
    			getMap->tile[caseToUpdate] = arcade::TileType::EMPTY;
    		else if (snake->getMap()->getCaseInfo(width, height) == Map::Info::POWERUP)
    			getMap->tile[caseToUpdate] = arcade::TileType::POWERUP;
        ++width;
      }
      ++height;
    }
  	std::cout.write(reinterpret_cast<char *>(getMap), sizeOfStruct);

}

extern "C"  void		Play(void)
{
  arcade::CommandType command;
  Snake *snake = new Snake(12, 12);

  while (std::cin)
  {
    std::cin.read(reinterpret_cast<char *>(&command), sizeof(arcade::CommandType));
    if (command == arcade::CommandType::WHERE_AM_I)
      getWhereAmI(command, snake);
    else if (command == arcade::CommandType::GET_MAP)
      getMapToGetMap(command, snake);
    else if (command == arcade::CommandType::GO_UP)
      snake->setDir(Snake::Direction::UP);
    else if (command == arcade::CommandType::GO_DOWN)
      snake->setDir(Snake::Direction::DOWN);
    else if (command == arcade::CommandType::GO_LEFT)
      snake->setDir(Snake::Direction::LEFT);
    else if (command == arcade::CommandType::GO_RIGHT)
      snake->setDir(Snake::Direction::RIGHT);
    else if (command == arcade::CommandType::PLAY)
      snake->goPlay();
    }
}
