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

InputManager::InputManager(LibManager *lman, IDisplay *lib) : _Lman(lman), _lib(lib)
{
  DIR *dir;
  struct dirent *entry;

  if (!(dir = opendir("./lib")))
    return ;
  while ((entry = readdir(dir)))
    {
      if (entry->d_name[0] != '.')
	_libs.push_back(entry->d_name);
    }
  closedir(dir);
}

InputManager::~InputManager()
{
}

void InputManager::do_action(int &is_running, Input in)
{
  if (in == PREV_LIB)
    switch_lib(0);
  else if (in == NEXT_LIB)
    switch_lib(1);
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
    launch_game();
}

std::string InputManager::name_next_lib(int mode)
{
  for (unsigned int i = 0; i < _libs.size(); i++)
    {
      if (mode == 1 && _libs[i] == _Lman->getLib().substr(_Lman->getLib().find_last_of("/") + 1))
	return ((i == _libs.size() - 1) ? _libs[0] : _libs[i + 1]);
      else if (mode == 0 && _libs[i] == _Lman->getLib().substr(_Lman->getLib().find_last_of("/") + 1))
	return ((i == 0) ?  _libs[_libs.size() - 1] : _libs[i - 1]);
    }
  return (NULL);
}

void InputManager::switch_lib(int mode)
{
  std::string lib_name;
  std::string dir("./lib/");
  func clone;

  lib_name = name_next_lib(mode);
  if (!lib_name.c_str())
    return ;
  if (static_cast<std::string>(lib_name) == _Lman->getLib())
    return ;
  delete _lib;
  _Lman->Switch(dir + lib_name);
  clone = (func)dlsym(_Lman->getHandle(), "clone");
  _lib = clone();
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
