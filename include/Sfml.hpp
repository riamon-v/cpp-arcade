//
// Sfml.hpp for Sfml in /home/riamon_v/rendu/CPP/cpp_arcade/include
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Mon Apr 10 20:56:56 2017 Riamon Vincent
// Last update Fri Apr 14 16:48:13 2017 Riamon Vincent
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
  void display(std::vector<TileInfo> const &_tiles) const;
  void displayMenu(const t_info_menu &) const;
  Input getInputs() const;
  void kill();
  void draw_case(const unsigned int , const unsigned int , const sf::Color &) const;
private:
  sf::RenderWindow *_window;
  std::map<sf::Keyboard::Key, Input> _inputs;
};

namespace cln
{
  extern "C" IDisplay *clone();
};

#endif //SFML_HPP_
