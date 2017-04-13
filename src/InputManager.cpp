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

InputManager::InputManager(LibManager *lman, IDisplay *lib, int run) : _Lman(lman), _lib(lib), is_running(run)
{
  DIR *dir;
  struct dirent *entry;

  // _snk = new Snake(MAP_W, MAP_H);
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

void InputManager::do_action(Input in)
{
  /*  std::map<Input, std::function<void()>> _fun;

      _fun[PREV_LIB] = [this] () {
      this->switch_lib(0);
      };
      _fun[NEXT_LIB] = [this] () {
      this->switch_lib(1);
      };
      _fun[PREV_GAME] = [this] () {
      this->switch_game(0);
      };
      _fun[NEXT_GAME] = [this] () {
      this->switch_game(1);
      };
      _fun[RESTART] = [this] () {
      this->restart(); //TODO à voir
      };
      _fun[MENU] = [this] () {
      this->menu(); //TODO à voir
      };
      _fun[EXIT] = [this] () {
      this->my_exit();
      };
      _fun[RIGHT] = [this] () {
      this->goRight();
      };
      _fun[LEFT] = [this] () {
      this->goLeft();
      };
      _fun[UP] = [this] () {
      this->goUp();
      };
      _fun[DOWN] = [this] () {
      this->goDown();
      };
      _fun[PLAY] = [this] () {
      this->launch_game(); //TODO à voir
      };

      try   {
      _fun[in]();
      }catch (std::exception const &err) {
      }*/
  if (in == PREV_LIB)
    switch_lib(0);
  else if (in == NEXT_LIB)
    switch_lib(1);
  else if (in == PREV_GAME)
    switch_game(0);
  else if (in == NEXT_GAME)
    switch_game(1);
  else if (in == RESTART)
    restart();
  else if (in == MENU)
    menu();
  else if (in == EXIT)
    my_exit();
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
  if (InputManager::is_running)
    delete _lib;
  std::cout << "Switch to " << lib_name << std::endl;
  _Lman->Switch(dir + lib_name);
  clone = (func)dlsym(_Lman->getHandle(), "clone");
  _lib = clone();
}

void InputManager::switch_game(int mode)
{
  (void)mode;
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

void InputManager::my_exit()
{
  InputManager::is_running = 0;
  std::cout << "Exit" << std::endl;
}

void InputManager::goRight()
{
  // _snk->setDir(Snake::Direction::RIGHT);
  std::cout << "Go Right" << std::endl;
}

void InputManager::goLeft()
{
  // _snk->setDir(Snake::Direction::LEFT);
  std::cout << "Go Left" << std::endl;
}

void InputManager::goUp()
{
  //_snk->setDir(Snake::Direction::UP);
  std::cout << "Go Up" << std::endl;
}

void InputManager::goDown()
{
  //  _snk->setDir(Snake::Direction::DOWN);
  std::cout << "Go Down" << std::endl;
}

void InputManager::launch_game()
{
  std::cout << "Start game" << std::endl;
}
