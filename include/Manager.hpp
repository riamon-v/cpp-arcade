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
  void menu();
  void my_exit();
  void goRight();
  void goLeft();
  void goUp();
  void goDown();
  void launch_game();

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
