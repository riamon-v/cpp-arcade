//
// main.cpp for main in /home/riamon_v/rendu/CPP/cpp_arcade/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Thu Apr  6 18:56:31 2017 Riamon Vincent
// Last update Tue Apr 11 21:53:34 2017 Riamon Vincent
//

#include <unistd.h>
#include "IDisplay.hpp"
#include "LibManager.hpp"
#include "Manager.hpp"
#include "Snake.hpp"

void		main_loop(IDisplay *lib, LibManager *lman)
{
  Manager Iman(lman, lib, 1);
  // Snake		snk(MAP_W, MAP_H);

  // Iman._snk = snk;
  while (Iman.is_running)
    {
      //Input gestion
      Iman.do_action(Iman._lib->getInputs());
      //Game logic
      //      Iman._snk->goPlay();
      //Display
      //Iman._lib->display();
      //usleep(500000);
    }
  delete Iman._lib;
  delete Iman._Lman;
}

int		main(int argc, char **argv)
{
  IDisplay	*lib;
  LibManager	*Lman;
  func		clone;

  if (argc != 2)
    {
      std::cerr << argv[0] << " [LIBRARY NAME]" << std::endl;
      return (84);
    }
  Lman = new LibManager(argv[1]);
  if (Lman->Error())
    return ((std::cerr << Lman->Error() << std::endl) && 1);
  clone = (func)dlsym(Lman->getHandle(), "clone");
  Lman->setError(dlerror());
  if (Lman->Error())
    return ((std::cerr<< Lman->Error() << std::endl) && 1);
  lib = clone();
  main_loop(lib, Lman);
  return (0);
}
