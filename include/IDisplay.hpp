//
// IDisplay.hpp for IDisplay in /home/riamon_v/rendu/CPP/cpp_arcade/include
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Mon Apr 10 21:05:22 2017 Riamon Vincent
// Last update Fri Apr 14 16:57:27 2017 Melvin Personnier
//

#ifndef __IDISPLAY_HPP__
# define __IDISPLAY_HPP__

#include <vector>
#include <iostream>
#include "ILogic.hpp"

#define WIN_H 620
#define WIN_W 560
#define MAP_H 31
#define MAP_W 27

enum Input {
  UNDEFINED = 0,
  PREV_LIB,
  NEXT_LIB,
  PREV_GAME,
  NEXT_GAME,
  RESTART,
  MENU,
  EXIT,
  RIGHT,
  LEFT,
  UP,
  DOWN,
  PLAY
};

typedef struct		s_value_menu {
  std::string			value;
  int				checked;
  int				pointed;
}				t_value_menu;

typedef struct		s_info_menu {
  std::vector<t_value_menu>	games;
  std::vector<t_value_menu>	graphics;
  std::vector<t_value_menu>	score;
  std::string			playerName;
  unsigned int		timer;
}				t_info_menu;

class IDisplay {
public:
  virtual ~IDisplay() { }
  virtual int configure(unsigned int width, unsigned int height) = 0;
  virtual Input getInputs() const = 0;
  virtual void display(std::vector<TileInfo> const &_tiles) const = 0;
  virtual void displayMenu(void *data) const = 0;
  virtual void kill() = 0;
};

typedef IDisplay *(*func_display)();

#endif // __IDISPLAY_HPP__
