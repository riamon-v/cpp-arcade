//
// lapin.cpp for lapin in /home/riamon_v/rendu/CPP/cpp_arcade/src/src_liblapin/src
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Mon Apr 10 20:52:22 2017 Riamon Vincent
// Last update Tue Apr 11 10:02:52 2017 Riamon Vincent
//

#include "Llapin.hpp"

Lapin::Lapin()
{
  _inputs[BKS_2] = PREV_LIB;
  _inputs[BKS_3] = NEXT_LIB;
  _inputs[BKS_4] = PREV_GAME;
  _inputs[BKS_5] = PREV_GAME;
  _inputs[BKS_8] = RESTART;
  _inputs[BKS_9] = MENU;
  _inputs[BKS_ESCAPE] = EXIT;
  _inputs[BKS_RIGHT] = RIGHT;
  _inputs[BKS_LEFT] = LEFT;
  _inputs[BKS_UP] = UP;
  _inputs[BKS_DOWN] = DOWN;
  _inputs[BKS_RETURN] = PLAY;
  std::cout << "Lapin" << std::endl;
  configure(500, 500);
}

Lapin::~Lapin()
{
}

int Lapin::configure(unsigned int width, unsigned int height)
{
  _win = bunny_start(width, height, 0, "Arcade");
  _pix = bunny_new_pixelarray(width, height);
  bunny_blit(&_win->buffer, &_pix->clipable, 0);
  bunny_display(_win);
  return (0);
}

void Lapin::display(void *data) const
{
  (void)data;
}

void Lapin::displayMenu(void *data) const
{
  (void)data;
}

Input Lapin::getInputs() const
{
}

void Lapin::kill()
{
}

IDisplay *cln::clone()
{
  return new Lapin;
}
