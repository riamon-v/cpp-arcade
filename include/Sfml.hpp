//
// Sfml.hpp for Sfml in /home/riamon_v/rendu/CPP/cpp_arcade/include
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Mon Apr 10 20:56:56 2017 Riamon Vincent
// Last update Tue Apr 11 19:16:22 2017 Riamon Vincent
//

#ifndef SFML_HPP_
# define SFML_HPP_

#include <map>
#include <SFML/Graphics.hpp>
#include "IDisplay.hpp"

class Sfml : public IDisplay
{
public:
  Sfml();
  virtual ~Sfml();
  int configure(unsigned int width, unsigned int height);
  void display(void *data) const;
  void displayMenu(void *data) const;
  Input getInputs() const;
  void kill();
  void draw_case(const unsigned int , const unsigned int , const sf::Color &);
private:
  sf::RenderWindow *_window;
  std::map<sf::Keyboard::Key, Input> _inputs;
};

namespace cln
{
  extern "C" IDisplay *clone();
};

#endif //SFML_HPP_