//
// Ncurses.hpp for Ncurses in /home/riamon_v/rendu/CPP/cpp_arcade/include
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Mon Apr 10 20:56:56 2017 Riamon Vincent
// Last update Fri Apr 14 16:48:24 2017 Riamon Vincent
//

#ifndef NCURSES_HPP_
# define NCURSES_HPP_

#include <ncurses.h>
#include <map>
#include <algorithm>
#include "IDisplay.hpp"

class Ncurses : public IDisplay
{
public:
  Ncurses();
  virtual ~Ncurses();
  int configure(unsigned int width, unsigned int height);
  void display(std::vector<TileInfo> const &_tiles) const;
  void displayMenu(const t_info_menu &) const;
  Input getInputs() const;
  void kill();
  void draw_case(unsigned int, unsigned int, const unsigned int) const;

private:
  int _y;
  int _x;
  WINDOW *_win;
  mutable std::vector<uint32_t> _colors;
  std::map<int, Input> _inputs;

  void displayElements(const std::vector<t_value_menu> &tab, const std::string &s,
                        const unsigned int begin) const;
};

namespace cln
{
  extern "C" IDisplay *clone();
};

#endif //NCURSES_HPP_
