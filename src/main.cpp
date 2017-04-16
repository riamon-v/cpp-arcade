//
// main.cpp for main in /home/riamon_v/rendu/CPP/cpp_arcade/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Thu Apr  6 18:56:31 2017 Riamon Vincent
// Last update Fri Apr 14 16:21:32 2017 Riamon Vincent
//

#include <unistd.h>
#include "Manager.hpp"
#include "Snake.hpp"

bool		mainLoop(Manager &Iman)
{
  gameLib s;

  Iman.restart();
  s = Iman.menu();
  if (s.game == "" || s.lib == "")
    return (false);
  if (s.lib != Iman._Lman->getName().substr(Iman._Lman->getName().find_last_of("/") + 1))
    Iman.switch_lib(s.lib);
  if (s.game != Iman._Gman->getName().substr(Iman._Gman->getName().find_last_of("/") + 1))
    Iman.switch_game(s.game);
  while (Iman.is_running)
    {
      //Input gestion
      try {
          Input t = Iman._lib->getInputs();
          if (t == MENU)
              return (true);
	         Iman.do_action(t);
	         //Game logic
	         usleep(Iman._game->getSpeed());
	         Iman._game->runCommand(arcade::CommandType::PLAY);
	          //Display
	          Iman._lib->display(Iman._game->getTiles());
      } catch (GameOver const &err) {
	       std::cout << err.what() << std::endl;
         return (true);
      }
    }
    return (false);
}

int		main(int argc, char **argv)
{
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
  Gman = new GLManager("games/lib_arcade_snake.so");
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
  Manager Iman(Lman, clone(), Gman, clone_game());
  while (mainLoop(Iman));
  return (0);
}
