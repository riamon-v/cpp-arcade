//
// lapin.cpp for lapin in /home/riamon_v/rendu/CPP/cpp_arcade/src/src_liblapin/src
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Mon Apr 10 20:52:22 2017 Riamon Vincent
// Last update Tue Apr 11 13:36:36 2017 Riamon Vincent
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
  _in = UNDEFINED;
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

t_bunny_response Lapin::pseudo_events(t_bunny_event_state st,
				      t_bunny_keysym key, void *ptr)
{
  (void)ptr;
  if (st == GO_DOWN && bunny_get_keyboard()[key])
    _in = _inputs[key];
  else
    _in = UNDEFINED;
  std::cout << _in << std::endl;
  return (GO_ON);
}

t_bunny_response Lapin::pseudo_loop(void *d)
{
  (void)d;
  return (EXIT_ON_SUCCESS);
}

Input Lapin::getInputs() const
{
  bunny_set_loop_main_function(pseudo_loop);
  bunny_set_key_response((t_bunny_key)&pseudo_events);
  bunny_loop(_win, 100, NULL);
  return (_in);
}

void Lapin::kill()
{
  bunny_stop(_win);
}

IDisplay *cln::clone()
{
  return new Lapin;
}
