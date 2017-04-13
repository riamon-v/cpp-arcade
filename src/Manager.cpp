//
// inputFunction.cpp for inputFunction in /home/riamon_v/rendu/CPP/cpp_arcade/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Thu Apr  6 18:54:40 2017 Riamon Vincent
// Last update Mon Apr 10 17:47:27 2017 Riamon Vincent
//

#include "Manager.hpp"

Manager::Manager(LibManager *lman, IDisplay *lib, int run) : _Lman(lman), _lib(lib), is_running(run)
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

Manager::~Manager()
{
}

void Manager::do_action(Input in)
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

std::string Manager::name_next_lib(int mode)
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

void Manager::switch_lib(int mode)
{
  std::string lib_name;
  std::string dir("./lib/");
  func clone;

  lib_name = name_next_lib(mode);
  if (!lib_name.c_str())
    return ;
  if (static_cast<std::string>(lib_name) == _Lman->getLib())
    return ;
  if (Manager::is_running)
    delete _lib;
  std::cout << "Switch to " << lib_name << std::endl;
  _Lman->Switch(dir + lib_name);
  clone = (func)dlsym(_Lman->getHandle(), "clone");
  _lib = clone();
}

void Manager::switch_game(int mode)
{
  (void)mode;
  std::cout << "Switch Game" << std::endl;
}

void Manager::restart()
{
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
  if (v.size() >= i)
  {
    v[0].pointed = 1;
    return ;
  }
  if (c)
  {
    v[i].pointed = 0;
    v[(i + 1 >= v.size() ? 0 : i + 1)].pointed = 1;
  }
  else
  {
    v[i].pointed = 0;
    v[(i <= 0 ? v.size() - 1 : i - 1)].pointed = 1;
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
  else if (inp == Input::PREV_GAME || (inp == Input::DOWN && s.games[0].checked))
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
    v.pointed = (_libs[i] == _Lman->getLib());
    s.graphics.push_back(v);
  }

  while (run)
  {
    Input inp;
    if ((inp = _lib->getInputs()) != Input::UNDEFINED)
    {
      _runCmdMenu(inp, s, run, ret);
      _lib->displayMenu(&s);
    }
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
  // _snk->setDir(Snake::Direction::RIGHT);
  std::cout << "Go Right" << std::endl;
}

void Manager::goLeft()
{
  // _snk->setDir(Snake::Direction::LEFT);
  std::cout << "Go Left" << std::endl;
}

void Manager::goUp()
{
  //_snk->setDir(Snake::Direction::UP);
  std::cout << "Go Up" << std::endl;
}

void Manager::goDown()
{
  //  _snk->setDir(Snake::Direction::DOWN);
  std::cout << "Go Down" << std::endl;
}

void Manager::launch_game()
{
  std::cout << "Start game" << std::endl;
}
