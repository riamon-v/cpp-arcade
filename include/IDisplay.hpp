//
// IDisplay.hpp for IDisplay in /home/riamon_v/rendu/CPP/cpp_arcade/include
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Mon Apr 10 21:05:22 2017 Riamon Vincent
// Last update Tue Apr 11 17:58:27 2017 Riamon Vincent
//

#ifndef __IDISPLAY_HPP__
# define __IDISPLAY_HPP__

#include <iostream>

#define WIN_H 600
#define WIN_W 600
#define MAP_H 20
#define MAP_W 20

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

class IDisplay {
public:
  virtual ~IDisplay() { }
  virtual int configure(unsigned int width, unsigned int height) = 0;
  virtual Input getInputs() const = 0;
  virtual void display(void *data) const = 0;
  virtual void displayMenu(void *data) const = 0;
  virtual void kill() = 0;
};

typedef IDisplay *(*func)();

#endif // __IDISPLAY_HPP__
