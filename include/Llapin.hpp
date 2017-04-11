//
// Llapin.hpp for Llapin in /home/riamon_v/rendu/CPP/cpp_arcade/include
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Mon Apr 10 18:55:43 2017 Riamon Vincent
// Last update Tue Apr 11 10:01:39 2017 Riamon Vincent
//

#ifndef LLAPIN_HPP_
# define LLAPIN_HPP_

#include <lapin.h>
#include <map>
#include "IDisplay.hpp"

class Lapin : public IDisplay
{
public:
  Lapin();
  ~Lapin();
  int configure(unsigned int width, unsigned int height);
  void display(void *data) const;
  void displayMenu(void *data) const;
  Input getInputs() const;
  void kill();

private:
  t_bunny_window *_win;
  t_bunny_pixelarray *_pix;
  std::map<t_bunny_keysym, Input> _inputs;
};

namespace cln
{
  extern "C" IDisplay *clone();
};

#endif //LLAPIN_HPP_
