//
// inputFunction.cpp for inputFunction in /home/riamon_v/rendu/CPP/cpp_arcade/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Thu Apr  6 18:54:40 2017 Riamon Vincent
// Last update Thu Apr 13 18:57:25 2017 Riamon Vincent
//

#include "Manager.hpp"

Manager::Manager(GLManager *lman, IDisplay *lib, GLManager *gman, ILogic *game) :
  _Lman(lman), _lib(lib), _Gman(gman), _game(game)
{
  DIR *dir_lib;
  DIR *dir_game;
  struct dirent *entry;

  is_running = 1;
  if (!(dir_lib = opendir("./lib")) || !(dir_game = opendir("./games")))
    return ;
  while ((entry = readdir(dir_lib)))
    {
      if (entry->d_name[0] != '.')
	_libs.push_back(entry->d_name);
    }
  while ((entry = readdir(dir_game)))
    {
      if (entry->d_name[0] != '.')
	_games.push_back(entry->d_name);
    }
  closedir(dir_lib);
  closedir(dir_game);
}

Manager::~Manager()
{
}

void Manager::do_action(Input in)
{
  std::map<Input, std::function<void()>> _fun;

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

  if (in != UNDEFINED)
    _fun[in]();
  // if (in == PREV_LIB)
  //   switch_lib(0);
  // else if (in == NEXT_LIB)
  //   switch_lib(1);
  // else if (in == PREV_GAME)
  //   switch_game(0);
  // else if (in == NEXT_GAME)
  //   switch_game(1);
  // else if (in == RESTART)
  //   restart();
  // else if (in == MENU)
  //   menu();
  // else if (in == EXIT)
  //   my_exit();
  // else if (in == RIGHT)
  //   goRight();
  // else if (in == LEFT)
  //   goLeft();
  // else if (in == UP)
  //   goUp();
  // else if (in == DOWN)
  //   goDown();
  // else if (in == PLAY)
  //   launch_game();
}

std::string Manager::name_next_lib(int mode)
{
  for (unsigned int i = 0; i < _libs.size(); i++)
    {
      if (mode == 1 && _libs[i] == _Lman->getName().substr(_Lman->getName().find_last_of("/") + 1))
	return ((i == _libs.size() - 1) ? _libs[0] : _libs[i + 1]);
      else if (mode == 0 && _libs[i] == _Lman->getName().substr(_Lman->getName().find_last_of("/") + 1))
	return ((i == 0) ?  _libs[_libs.size() - 1] : _libs[i - 1]);
    }
  return (NULL);
}

std::string Manager::name_next_game(int mode)
{
  for (unsigned int i = 0; i < _games.size(); i++)
    {
      if (mode == 1 && _games[i] == _Gman->getName().substr(_Gman->getName().find_last_of("/") + 1))
	return ((i == _games.size() - 1) ? _games[0] : _games[i + 1]);
      else if (mode == 0 && _games[i] == _Gman->getName().substr(_Gman->getName().find_last_of("/") + 1))
	return ((i == 0) ?  _games[_games.size() - 1] : _games[i - 1]);
    }
  return (NULL);
}

void Manager::switch_lib(int mode)
{
  std::string lib_name;
  std::string dir("./lib/");
  func_display clone;

  lib_name = name_next_lib(mode);
  if (!lib_name.c_str())
    return ;
  if (lib_name == _Lman->getName())
    return ;
  if (Manager::is_running)
    delete _lib;
  std::cout << "Switch to Lib " << lib_name << std::endl;
  _Lman->Switch(dir + lib_name);
  clone = (func_display)dlsym(_Lman->getHandle(), "clone");
  _lib = clone();
}

void Manager::switch_game(int mode)
{
  std::string game_name;
  std::string dir("./games/");
  func_logic clone;

  game_name = name_next_game(mode);
  if (!game_name.c_str())
    return ;
  if (game_name == _Gman->getName())
    return ;
  if (Manager::is_running)
    delete _game;
  std::cout << "Switch to Game " << game_name << std::endl;
  _Gman->Switch(dir + game_name);
  clone = (func_logic)dlsym(_Gman->getHandle(), "clone");
  _game = clone();
}

void Manager::restart()
{
  std::cout << "Restart Game" << std::endl;
}

void Manager::menu()
{
  std::cout << "Display Menu" << std::endl;
}

void Manager::my_exit()
{
  Manager::is_running = 0;
  std::cout << "Exit" << std::endl;
}

void Manager::goRight()
{
  _game->runCommand(arcade::CommandType::GO_RIGHT);
}

void Manager::goLeft()
{
 _game->runCommand(arcade::CommandType::GO_LEFT);
}

void Manager::goUp()
{
  _game->runCommand(arcade::CommandType::GO_UP);
}

void Manager::goDown()
{
  _game->runCommand(arcade::CommandType::GO_DOWN);
}

void Manager::launch_game()
{
  std::cout << "Start game" << std::endl;
}
