//
// Sfml.hpp for Sfml in /home/riamon_v/rendu/CPP/cpp_arcade/include
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Mon Apr 10 20:56:56 2017 Riamon Vincent
// Last update Mon Apr 10 22:24:50 2017 Riamon Vincent
//

#ifndef SFML_HPP_
# define SFML_HPP_

#include "IDisplay.hpp"

class Sfml : public IDisplay
{
public:
  Sfml();
  ~Sfml();
  int configure(unsigned int width, unsigned int height);
  void display(void *data) const;
  void displayMenu(void *data) const;
  Input getInputs() const;
  void kill();
};

namespace cln
{
  extern "C" IDisplay *clone();
};

#endif //SFML_HPP_
