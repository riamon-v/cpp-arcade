//
// sfml.cpp for sfml in /home/riamon_v/rendu/CPP/cpp_arcade/src/src_liblapin/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Mon Apr 10 21:02:03 2017 Riamon Vincent
// Last update Thu Apr 13 22:01:46 2017 Riamon Vincent
//

#include "Sfml.hpp"

Sfml::Sfml()
{
  _window = new sf::RenderWindow(sf::VideoMode(WIN_W, WIN_H), "Arcade");

  _inputs[sf::Keyboard::Num2] = PREV_LIB;
  _inputs[sf::Keyboard::Num3] = NEXT_LIB;
  _inputs[sf::Keyboard::Num4] = PREV_GAME;
  _inputs[sf::Keyboard::Num5] = NEXT_GAME;
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

void Sfml::draw_case(const unsigned int x, const unsigned int y,
                    const sf::Color &color)
{
  sf::RectangleShape rectangle(sf::Vector2f((WIN_W / MAP_W), (WIN_H / MAP_H)));
  rectangle.setPosition(sf::Vector2f(x, y));
  rectangle.setFillColor(color);
  _window->draw(rectangle);
}

int Sfml::configure(unsigned int width, unsigned int height)
{
  if (_window->isOpen())
    _window->setSize(sf::Vector2u(width, height));
  return (0);
}

void Sfml::display(std::vector<TileInfo> const &_tiles)// const
{
  sf::Color col;
  unsigned int x;
  unsigned int y;

  x = 0;
  y = 0;
  for (int i = 0; i < MAP_W * MAP_H; i++)
    {
      if (i != 0 && !(i % MAP_W))
	{
	  x = 0;
	  y += WIN_H / MAP_H;
	}
      draw_case(x, y, sf::Color(_tiles[i].color.rgba[2],
				_tiles[i].color.rgba[1],
				_tiles[i].color.rgba[0]));
      x += WIN_W / MAP_W;
    }
  _window->display();
}

void Sfml::displayMenu(void *data) const
{
  (void)data;
  sf::RectangleShape btn1(sf::Vector2f((WIN_W / MAP_W), (WIN_H / MAP_H)));
  sf::RectangleShape btn2(sf::Vector2f((WIN_W / MAP_W), (WIN_H / MAP_H)));

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
