//
// inputFunction.cpp for inputFunction in /home/riamon_v/rendu/CPP/cpp_arcade/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Thu Apr  6 18:54:40 2017 Riamon Vincent
// Last update Fri Apr 14 23:22:03 2017 Riamon Vincent
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
  delete _lib;
  delete _Lman;
  delete _game;
  delete _Gman;
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
    this->restart();
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

void Manager::switch_lib(const int mode)
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

void Manager::switch_game(const int mode)
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

void Manager::switch_lib(const std::string &lib)
{
  std::string dir("./lib/");
  func_display clone;

  if (Manager::is_running)
    delete _lib;
  _Lman->Switch(dir + lib);
  clone = (func_display)dlsym(_Lman->getHandle(), "clone");
  _lib = clone();
}

void Manager::switch_game(const std::string &game)
{
  std::string dir("./games/");
  func_logic clone;

  if (Manager::is_running)
    delete _game;
  _Gman->Switch(dir + game);
  clone = (func_logic)dlsym(_Gman->getHandle(), "clone");
  _game = clone();
}

void Manager::restart()
{
  func_logic clone;

  delete _game;
  _Gman->Switch(_Gman->getName());
  clone  = (func_logic)dlsym(_Gman->getHandle(), "clone");
  _game = clone();
  std::cout << "Restart Game" << std::endl;
}

void Manager::_moveChecked(std::vector<t_value_menu> &v1, std::vector<t_value_menu> &v2)
{
  for (size_t i = 0; i < v1.size(); i++) {
    v1[i].checked = !v1[i].checked;
  }

  for (size_t i = 0; i < v2.size(); i++) {
    v2[i].checked = !v2[i].checked;
  }
}

void Manager::_movePointed(std::vector<t_value_menu> &v, const char c)
{
  unsigned int i = 0;

  while (i < v.size() && !v[i].pointed)
   i = i + 1;
  if (i >= v.size())
  {
    v[0].pointed = 1;
    return ;
  }
  if (c)
  {
    v[i].pointed = 0;
    v[(i + 1 >= v.size() ? 0 : i + 1)].pointed = true;
  }
  else
  {
    v[i].pointed = 0;
    v[(i <= 0 ? v.size() - 1 : i - 1)].pointed = true;
  }
}

void Manager::_getPointedElems(const t_info_menu &s, gameLib &ret)
{
  for (size_t i = 0; i < s.graphics.size(); i++) {
    if (s.graphics[i].pointed)
      ret.lib = s.graphics[i].value;
  }

  for (size_t i = 0; i < s.games.size(); i++) {
    if (s.games[i].pointed)
      ret.game = s.games[i].value;
  }
}

void Manager::_runCmdMenu(const Input inp, t_info_menu &s, bool &run, gameLib &ret)
{
  if (inp == Input::NEXT_LIB || (inp == Input::DOWN && s.graphics[0].checked))
    _movePointed(s.graphics, 1);
  else if (inp == Input::NEXT_GAME || (inp == Input::DOWN && s.games[0].checked))
    _movePointed(s.games, 1);
  else if (inp == Input::PREV_LIB || (inp == Input::UP && s.graphics[0].checked))
    _movePointed(s.graphics, 0);
  else if (inp == Input::PREV_GAME || (inp == Input::UP && s.games[0].checked))
    _movePointed(s.games, 0);
  else if (inp == Input::LEFT || inp == Input::RIGHT)
    _moveChecked(s.games, s.graphics);
  else if (inp == Input::PLAY || inp == Input::EXIT)
    {
      run = false;
      if (inp == Input::PLAY)
        _getPointedElems(s, ret);
    }
}

gameLib Manager::menu()
{
  t_info_menu s;
  t_value_menu v;
  gameLib ret;
  bool  run = true;

  ret.game = "";
  ret.lib = "";
  for (size_t i = 0; i < _libs.size(); i++) {
    v.value = _libs[i];
    v.checked = 0;
    v.pointed = (_libs[i] ==
                  _Lman->getName().substr(_Lman->getName().find_last_of("/") + 1));
    s.graphics.push_back(v);
  }

  for (size_t i = 0; i < _games.size(); i++) {
    v.value = _games[i];
    v.checked = 1;
    v.pointed = (i == 0);
    s.games.push_back(v);
  }

  while (run)
  {
    usleep(30000);
    Input inp;
    if ((inp = _lib->getInputs()) != Input::UNDEFINED)
      _runCmdMenu(inp, s, run, ret);
    _lib->displayMenu(s);
  }
 return (ret);
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
