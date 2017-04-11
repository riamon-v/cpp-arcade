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

void		main_loop()
{
  int		is_running;

  is_running = 1;
  while (is_running)
    {
      //Input gestion
      //Game logic
      //Display
    }
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
  lib->getInputs();
  delete lib;
  delete Lman;
  return (0);
}
