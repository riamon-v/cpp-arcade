//
// IDisplay.hpp for IDisplay in /home/riamon_v/rendu/CPP/cpp_arcade/include
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Mon Apr 10 21:05:22 2017 Riamon Vincent
// Last update Mon Apr 10 22:23:38 2017 Riamon Vincent
//

#ifndef __IDISPLAY_HPP__
# define __IDISPLAY_HPP__

#include <iostream>

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
