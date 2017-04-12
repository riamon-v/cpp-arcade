#ifndef INPUTMANAGER_HPP_
# define INPUTMANAGER_HPP_

#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <map>
#include <functional>
#include <utility>
#include "IDisplay.hpp"
#include "LibManager.hpp"

class InputManager
{
public:
  InputManager(LibManager *, IDisplay *, int);
  ~InputManager();
  void do_action(Input);
  std::string name_next_lib(int mode);
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
  LibManager *_Lman;
  IDisplay *_lib;
  std::vector<std::string> _libs;
  int is_running;
};

#endif //INPUTMANAGER_HPP_
