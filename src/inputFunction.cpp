//
// inputFunction.cpp for inputFunction in /home/riamon_v/rendu/CPP/cpp_arcade/src
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Thu Apr  6 18:54:40 2017 Riamon Vincent
// Last update Mon Apr 10 17:47:27 2017 Riamon Vincent
//

#include "InputManager.hpp"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::do_action(LibManager& *lib, std::string new_libname
			     /*, IGame *game, std::string new_game*/, int &is_running,
			     Input in)
{
  if (in == PREV_LIB)
    lib = switch_lib(lib, new_libname);
  else if (in == NEXT_LIB)
    lib = switch_lib(lib, new_libname);
  else if (in == PREV_GAME)
    switch_game();
  else if (in == NEXT_GAME)
    switch_game();
  else if (in == RESTART)
    restart();
  else if (in == MENU)
    menu();
  else if (in == EXIT)
    exit(is_running);
  else if (in == RIGHT)
    goRight();
  else if (in == LEFT)
    goLeft();
  else if (in == UP)
    goUp();
  else if (in == DOWN)
    goDown();
  else if (in == PLAY)
    lauch_game();
}

LibManager *InputManager::switch_lib(LibManager& *old, std::string lib_name)
{
  std::cout << "Switch Lib" << std::endl;
  delete old;
  return (new LibManager(lib_name));
}

void InputManager::switch_game()
{
  std::cout << "Switch Game" << std::endl;
}

void InputManager::restart()
{
  std::cout << "Restart Game" << std::endl;
}

void InputManager::menu()
{
  std::cout << "Display Menu" << std::endl;
}

void InputManager::my_exit(int &is_running)
{
  is_running = 0;
  std::cout << "Exit" << std::endl;
}

void InputManager::goRight()
{
  std::cout << "Go Right" << std::endl;
}

void InputManager::goLeft()
{
  std::cout << "Go Left" << std::endl;
}

void InputManager::goUp()
{
  std::cout << "Go Up" << std::endl;
}

void InputManager::goDown()
{
  std::cout << "Go Down" << std::endl;
}

void InputManager::launch_game()
{
  std::cout << "Start game" << std::endl;
}
