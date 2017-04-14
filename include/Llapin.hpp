//
// Llapin.hpp for Llapin in /home/riamon_v/rendu/CPP/cpp_arcade/include
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Mon Apr 10 18:55:43 2017 Riamon Vincent
// Last update Fri Apr 14 17:05:01 2017 Riamon Vincent
//

#ifndef LLAPIN_HPP_
# define LLAPIN_HPP_

#include <lapin.h>
#include <map>
#include "IDisplay.hpp"

Input _in;
std::map<t_bunny_keysym, Input> _inputs;

class Lapin : public IDisplay
{
public:
  Lapin();
  virtual ~Lapin();
  int configure(unsigned int width, unsigned int height);
  void display(std::vector<TileInfo> const &_tiles) const;
  void displayMenu(void *data) const;
  Input getInputs() const;
  void kill();

public:
  static t_bunny_response pseudo_events(t_bunny_event_state st, t_bunny_keysym key,
  				 void *ptr);
  static t_bunny_response pseudo_loop(void *ptr);

public:
  void tekpixel(t_bunny_position *pos, unsigned int col) const;
  void color_full(t_bunny_pixelarray *pix, unsigned int col) const;
  void draw_case(t_bunny_position *pos, t_color *col) const;

private:
  mutable t_bunny_window *_win;
  mutable t_bunny_pixelarray *_pix;
};

namespace cln
{
  extern "C" IDisplay *clone();
};

#endif //LLAPIN_HPP_
