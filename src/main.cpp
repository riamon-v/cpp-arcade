//
// main.cpp for main in /home/riamon_v/rendu/CPP/cpp_arcade/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Thu Apr  6 18:56:31 2017 Riamon Vincent
// Last update Thu Apr 13 23:36:29 2017 Riamon Vincent
//

#include <unistd.h>
#include "Manager.hpp"
#include "Snake.hpp"

void		main_loop(IDisplay *lib, GLManager *lman, ILogic *game, GLManager *gman)
{
  Manager Iman(lman, lib, gman, game);

  while (Iman.is_running)
    {
      //Input gestion
      Iman.do_action(Iman._lib->getInputs());
      //Game logic
      usleep(80000);
      Iman._game->runCommand(arcade::CommandType::PLAY);
      //Display
      Iman._lib->display(Iman._game->getTiles());
    }
  delete Iman._lib;
  delete Iman._Lman;
  delete Iman._game;
  delete Iman._Gman;
}

int		main(int argc, char **argv)
{
  IDisplay	*lib;
  ILogic	*game;
  GLManager	*Lman;
  GLManager	*Gman;
  func_display	clone;
  func_logic	clone_game;

  if (argc != 2)
    {
      std::cerr << argv[0] << " [LIBRARY NAME]" << std::endl;
      return (84);
    }
  Lman = new GLManager(argv[1]);
  Gman = new GLManager("games/lib_arcade_pacman.so");
  if (Lman->Error())
    return ((std::cerr << Lman->Error() << std::endl) && 1);
  if (Gman->Error())
    return ((std::cerr << Gman->Error() << std::endl) && 1);
  clone = (func_display)dlsym(Lman->getHandle(), "clone");
  clone_game = (func_logic)dlsym(Gman->getHandle(), "clone");
  Lman->setError(dlerror());
  Gman->setError(dlerror());
  if (Lman->Error())
    return ((std::cerr<< Lman->Error() << std::endl) && 1);
  if (Gman->Error())
    return ((std::cerr<< Gman->Error() << std::endl) && 1);
  lib = clone();
  game = clone_game();
  main_loop(lib, Lman, game, Gman);
  return (0);
}
