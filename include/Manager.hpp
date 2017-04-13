#ifndef MANAGER_HPP_
# define MANAGER_HPP_

#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <map>
#include <functional>
#include <utility>
#include "IDisplay.hpp"
#include "ILogic.hpp"
#include "GLManager.hpp"

struct gameLib
{
  std::string game;
  std::string lib;
};

class Manager
{
public:
  Manager(GLManager *, IDisplay *, GLManager *, ILogic *);
  ~Manager();
  void do_action(Input);
  std::string name_next_lib(int mode);
  std::string name_next_game(int mode);
  void switch_lib(int mode);
  void switch_game(int mode);
  void restart();
  gameLib menu();
  void my_exit();
  void goRight();
  void goLeft();
  void goUp();
  void goDown();
  void launch_game();
  void _moveChecked(std::vector<t_value_menu> &v1, std::vector<t_value_menu> &v2);
  void _runCmdMenu(const Input inp, t_info_menu &s, bool &run, gameLib &ret);
  void _getPointedElems(const t_info_menu &s, gameLib &ret);
  void _movePointed(std::vector<t_value_menu> &v, const char c);

public:
  GLManager *_Lman;
  IDisplay *_lib;
  GLManager *_Gman;
  ILogic *_game;
  std::vector<std::string> _libs;
  std::vector<std::string> _games;
  int is_running;
};

#endif //MANAGER_HPP_
