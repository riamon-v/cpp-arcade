//
// ncurses.cpp for Ncurses in /home/riamon_v/rendu/CPP/cpp_arcade/src/src_liblapin/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Mon Apr 10 20:58:59 2017 Riamon Vincent
// Last update Tue Apr 11 21:36:33 2017 Riamon Vincent
//

#include "Ncurses.hpp"

Ncurses::Ncurses()
{
  _inputs[50] = PREV_LIB;
  _inputs[51] = NEXT_LIB;
  _inputs[52] = PREV_GAME;
  _inputs[53] = NEXT_GAME;
  _inputs[56] = RESTART;
  _inputs[57] = MENU;
  _inputs[27] = EXIT;
  _inputs[KEY_RIGHT] = RIGHT;
  _inputs[KEY_LEFT] = LEFT;
  _inputs[KEY_UP] = UP;
  _inputs[KEY_DOWN] = DOWN;
  _inputs[10] = PLAY;
  configure(WIN_W, WIN_H);
}

Ncurses::~Ncurses()
{
  kill();
}

void Ncurses::draw_case(unsigned int x, unsigned int y,
                       const unsigned int c)
{
  int    i;
  int    j;

  start_color();
  init_pair(c, c, c);
  wattron(_win, COLOR_PAIR(c));
  i = 0;
  while (i < (WIN_H / MAP_H) / 4)
  {
    j = 0;
    while (j < (WIN_W / MAP_W) / 8)
    {
      mvwprintw(_win, x, y, "%c", ' ');
      x = x + 1;
      j = j + 1;
    }
    x = x - j;
    i = i + 1;
    y = y + 1;
  }
  wattroff(_win, COLOR_PAIR(c));
}

int Ncurses::configure(unsigned int width, unsigned int height)
{
  (void)width;
  (void)height;
  initscr();
  getmaxyx(stdscr, _y, _x);
  _win = newwin(_y - 1, _x - 1, 1, 1);
  box(_win, 0, 0);
  keypad(_win, true);
  curs_set(0);
  timeout(0);
  nodelay(_win, true);
  return (0);
}

void Ncurses::display(void *data) const
{
  (void)data;
}

void Ncurses::displayMenu(void *data) const
{
  (void)data;
}

Input Ncurses::getInputs() const
{
  int ch;

  ch = wgetch(_win);
  if (((ch >= 50 && ch <= 57) || (ch >= 258 && ch <= 261) ||
       (ch == 27 || ch == 10)) && (ch != 54 && ch != 55))
    return (_inputs.at(ch));
  return (UNDEFINED);
}

void Ncurses::kill()
{
  delwin(_win);
  endwin();
}

IDisplay *cln::clone()
{
  return new Ncurses;
}
