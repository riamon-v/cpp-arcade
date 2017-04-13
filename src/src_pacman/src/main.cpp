//
// main.cpp for main in /home/riamon_v/rendu/CPP/cpp_arcade/src/src_pacman
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Fri Apr  7 16:29:42 2017 Riamon Vincent
// Last update Thu Apr 13 20:01:51 2017 Melvin Personnier
//

#include <unistd.h>
#include "Map.hpp"
#include "Pacman.hpp"

void Pacman::getWhereAmI(arcade::CommandType command, Pacman *pacman)
{
  pacman->getWhereAmI()->type = command;
  std::cout.write(reinterpret_cast<char *>(pacman->getWhereAmI()), sizeof(struct arcade::WhereAmI) +
    sizeof(arcade::Position));
}

void Pacman::getMapToGetMap(arcade::CommandType command, Pacman *pacman)
{
  int sizeOfStruct = sizeof(struct arcade::GetMap) +
    sizeof(arcade::TileType) * (pacman->getMap()->getWidth() * pacman->getMap()->getHeight());

  int caseToUpdate;

  // Alloue la structure sizeof(char) * sizeOfStruct
  arcade::GetMap *getMap = reinterpret_cast<struct arcade::GetMap*>
    (new char[sizeOfStruct]);

  int height = 0;
  int width = 0;

  getMap->type = command;
  getMap->height = pacman->getMap()->getHeight();
  getMap->width = pacman->getMap()->getWidth();

  while (height < pacman->getMap()->getHeight())
  {
      width = 0;
      while (width < pacman->getMap()->getWidth())
      {
        caseToUpdate = height * pacman->getMap()->getHeight() + width;
        if (pacman->getMap()->getCaseInfo(width, height) == Map::Info::EMPTY)
    			getMap->tile[caseToUpdate] = arcade::TileType::EMPTY;
    		else if (pacman->getMap()->getCaseInfo(width, height) == Map::Info::BLOCK)
    			getMap->tile[caseToUpdate] = arcade::TileType::BLOCK;
    		else if (pacman->getMap()->getCaseInfo(width, height) == Map::Info::DOOR)
    			getMap->tile[caseToUpdate] = arcade::TileType::BLOCK;
    		else if (pacman->getMap()->getCaseInfo(width, height) == Map::Info::POWERUP)
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
  Pacman *pacman = new Pacman(28, 31);

  while (std::cin)
  {
    std::cin.read(reinterpret_cast<char *>(&command), sizeof(arcade::CommandType));
    if (command == arcade::CommandType::WHERE_AM_I)
      pacman->getWhereAmI(command, pacman);
    else if (command == arcade::CommandType::GET_MAP)
      pacman->getMapToGetMap(command, pacman);
    else if (command == arcade::CommandType::GO_UP)
      pacman->setDir(Pacman::Direction::UP);
    else if (command == arcade::CommandType::GO_DOWN)
      pacman->setDir(Pacman::Direction::DOWN);
    else if (command == arcade::CommandType::GO_LEFT)
      pacman->setDir(Pacman::Direction::LEFT);
    else if (command == arcade::CommandType::GO_RIGHT)
      pacman->setDir(Pacman::Direction::RIGHT);
    else if (command == arcade::CommandType::PLAY)
      pacman->goPlay();
    }
}

// void print_tab(Map *test)
// {
//   int i = 0;
//   int j;
//   while (i < 31)
//   {
//     j = 0;
//     while (j < 28) {
//       if (test->getCaseInfo(j, i) == Map::BLOCK)
//         std::cout << "1";
//       if (test->getCaseInfo(j, i) == Map::EMPTY)
//         std::cout << "0";
//       if (test->getCaseInfo(j, i) == Map::POWERUP)
//           std::cout << "*";
//       if (test->getCaseInfo(j, i) == Map::DOOR)
//           std::cout << "-";
//       j++;
//       }
//       std::cout << std::endl;
//     i++;
//   }
// }
//
// int main()
// {
//   Map *test = new Map(28, 31);
//
//   print_tab(test);
// }
