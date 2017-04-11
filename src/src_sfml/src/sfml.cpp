//
// sfml.cpp for sfml in /home/riamon_v/rendu/CPP/cpp_arcade/src/src_liblapin/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Mon Apr 10 21:02:03 2017 Riamon Vincent
// Last update Tue Apr 11 21:56:37 2017 Riamon Vincent
//

#include "Sfml.hpp"

Sfml::Sfml()
{
  _window = new sf::Window(sf::VideoMode(WIN_W, WIN_H), "Arcade");

  _inputs[sf::Keyboard::Num2] = PREV_LIB;
  _inputs[sf::Keyboard::Num3] = NEXT_LIB;
  _inputs[sf::Keyboard::Num4] = PREV_GAME;
  _inputs[sf::Keyboard::Num5] = PREV_GAME;
  _inputs[sf::Keyboard::Num8] = RESTART;
  _inputs[sf::Keyboard::Num9] = MENU;
  _inputs[sf::Keyboard::Escape] = EXIT;
  _inputs[sf::Keyboard::Right] = RIGHT;
  _inputs[sf::Keyboard::Left] = LEFT;
  _inputs[sf::Keyboard::Up] = UP;
  _inputs[sf::Keyboard::Down] = DOWN;
  _inputs[sf::Keyboard::Return] = PLAY;

}

Sfml::~Sfml()
{
  kill();
  delete _window;
}

int Sfml::configure(unsigned int width, unsigned int height)
{
  if (_window->isOpen())
    _window->setSize(sf::Vector2u(width, height));
  return (0);
}

void Sfml::display(void *data) const
{
  (void)data;
}

void Sfml::displayMenu(void *data) const
{
  (void)data;
}

Input Sfml::getInputs() const
{
  sf::Event event;

  if (_window->pollEvent(event))
  {
      if (event.type == sf::Event::KeyPressed)
      {
        try {
          _inputs.at(event.key.code);
          return (_inputs.at(event.key.code));
        } catch (std::exception &e) {
          return (Input::UNDEFINED);
        }
      }
  }
  return (Input::UNDEFINED);
}

void Sfml::kill()
{
  if (_window->isOpen())
    _window->close();
}

IDisplay *cln::clone()
{
  return new Sfml;
}
