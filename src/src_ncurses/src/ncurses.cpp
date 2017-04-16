//
// ncurses.cpp for Ncurses in /home/riamon_v/rendu/CPP/cpp_arcade/src/src_liblapin/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Mon Apr 10 20:58:59 2017 Riamon Vincent
// Last update Fri Apr 14 16:47:31 2017 Riamon Vincent
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
                       const unsigned int c) const
{
  int    i;
  int    j;

  init_pair(c, c, c);
  wattron(_win, COLOR_PAIR(c));
  i = 0;
  while (i < (WIN_H / MAP_H) / 14)
  {
    j = 0;
    while (j < (WIN_W / MAP_W) / 7)
    {
      mvwprintw(_win, y, x , "%c", ' ');
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
  initscr();
  _win = newwin(height, width, 1, 1);
  keypad(_win, true);
  curs_set(0);
  timeout(0);
  nodelay(_win, true);
  return (0);
}

void Ncurses::display(std::vector<TileInfo> const &_tiles) const
{
  unsigned int x;
  unsigned int y;

  x = 0;
  y = 0;
  wclear(_win);
  start_color();
  for (int i = 0; i < MAP_W * MAP_H; i++)
    {
      if (i != 0 && !(i % MAP_W))
	     {
	        x = 0;
	        y += (WIN_H / MAP_H) / 14;
	     }
    if (find(_colors.begin(), _colors.end(), _tiles[i].color.hexacode) ==
          _colors.end())
      {
        init_color(_colors.size() + 1, _tiles[i].color.rgba[0],
                  _tiles[i].color.rgba[1], _tiles[i].color.rgba[2]);
        _colors.push_back(_tiles[i].color.hexacode);
      }
    unsigned int ic = 0;
    while (ic < _colors.size() && _colors[ic] != _tiles[i].color.hexacode)
      ic++;
    draw_case(x, y, ic >= _colors.size() ? _colors.size() : ic + 1);
    x += (WIN_W / MAP_W) / 7;
    }
  wrefresh(_win);
}

void Ncurses::displayElements(const std::vector<t_value_menu> &tab, const std::string &s,
                      const unsigned int begin) const{
    if (tab[0].checked)
    {
      mvwprintw(_win, 15, begin, "%s", "----------------------------------------");
      for (size_t i = 0; i < 20; i++) {
        mvwprintw(_win, 16 + i, begin, "%c", '|');
      }

      for (size_t i = 0; i < 19; i++) {
        mvwprintw(_win, 16 + i,  begin + 40, "%c", '|');
      }
      mvwprintw(_win, 35, begin, "%s", "----------------------------------------");
    }

  mvwprintw(_win, 17, begin + 17, "%s", s.c_str());

  for (size_t i = 0; i < tab.size(); i++) {
    mvwprintw(_win, 19 + (i * 2), begin + 10, "%s%s", tab[i].pointed ? "-> " : "",
              tab[i].value.c_str());
  }

}

void Ncurses::displayMenu(const t_info_menu &s) const
{
  wclear(_win);
  mvwprintw(_win, 5, 20, "%s", "ARCADE");
  mvwprintw(_win, 8, 5, "%s", "Created by : RIAMON - PERSONNE - MOMO");
  mvwprintw(_win, 11, 12, "%s", "Press ENTER to start...");

  displayElements(s.games, "GAMES", 0);
  displayElements(s.graphics, "GRAPHICS", 40);
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
