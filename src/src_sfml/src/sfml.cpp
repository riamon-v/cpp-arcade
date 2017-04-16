//
// sfml.cpp for sfml in /home/riamon_v/rendu/CPP/cpp_arcade/src/src_liblapin/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Mon Apr 10 21:02:03 2017 Riamon Vincent
// Last update Fri Apr 14 16:46:58 2017 Riamon Vincent
//

#include "Sfml.hpp"

Sfml::Sfml()
{
  _window = new sf::RenderWindow(sf::VideoMode(WIN_W, WIN_H), "Arcade : SFML");

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

  if (!_font.loadFromFile("src/src_sfml/fonts/Capriola-Regular.ttf"))
    std::cerr << "can't load the police.." << std::endl;
}

Sfml::~Sfml()
{
  kill();
  delete _window;
}

void Sfml::draw_case(const unsigned int x, const unsigned int y,
                    const sf::Color &color) const
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

void Sfml::display(std::vector<TileInfo> const &_tiles) const
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

void Sfml::_drawCenterTextInMenu(const std::string &str, const sf::Color &c,
                                const unsigned int h, const unsigned int size,
                                const unsigned int posWidth) const {
  sf::Text txt;

  txt.setFont(_font);
  txt.setString(str);
  txt.setCharacterSize(size);
  txt.setFillColor(c);
  sf::FloatRect txtRect = txt.getLocalBounds();
  txt.setOrigin(txtRect.left + txtRect.width/2.0f, 0);
  txt.setPosition(sf::Vector2f(posWidth, h));
  _window->draw(txt);

}

void Sfml::_drawCenterText(const std::string &str, const sf::Color &c,
  const float h, const unsigned int size) const
{
  sf::Text txt;

  txt.setFont(_font);
  txt.setString(str);
  txt.setCharacterSize(size);
  txt.setFillColor(c);
  sf::FloatRect txtRect = txt.getLocalBounds();
  txt.setOrigin(txtRect.left + txtRect.width/2.0f, 0);
  txt.setPosition(sf::Vector2f(_window->getSize().x/2.0f, h));
  _window->draw(txt);
}

void Sfml::_drawMenu(const std::vector<t_value_menu> &tab,
                    const unsigned int &begin, const std::string &name) const
{
  sf::RectangleShape rectangle(sf::Vector2f((_window->getSize().x / 2.0f) - 12,
                              _window->getSize().y - 266));
  rectangle.setFillColor(sf::Color(30, 31, 30));
  rectangle.setOutlineColor(tab[0].checked ? sf::Color(248, 168, 0) :
                            sf::Color(230, 230, 230));
  rectangle.setPosition(sf::Vector2f(begin + 6, 260));
  rectangle.setOutlineThickness(6);
  _window->draw(rectangle);
  _drawCenterTextInMenu(name, sf::Color(248, 168, 0), 280, 25,
                        _window->getSize().x / 4 + begin);
  unsigned int h = 330;
  rectangle.setOutlineThickness(0);
  for (size_t i = 0; i < tab.size(); i++) {
    sf::Color c;
    if (tab[i].pointed)
      c = sf::Color(248, 168, 0);
    else
      c = sf::Color(30, 31, 30);
    rectangle.setSize(sf::Vector2f(220, 60));
    sf::FloatRect rect = rectangle.getLocalBounds();
    rectangle.setOrigin(rect.left + rect.width/2.0f, 0);
    rectangle.setPosition(sf::Vector2f(_window->getSize().x/4 + begin, h));
    rectangle.setFillColor(c);
    _window->draw(rectangle);
    _drawCenterTextInMenu(tab[i].value, sf::Color(230, 230, 230), h + 15, 17,
                          _window->getSize().x / 4 + begin);
    h = h + 70;
  }
}

void Sfml::displayMenu(const t_info_menu &s) const
{
  sf::Text txt;

  _window->clear(sf::Color(30, 31, 30));
  txt.setStyle(sf::Text::Bold);
  _drawCenterText("ARCADE", sf::Color(248, 168, 0), 10, 62);
  _drawCenterText("Created by:", sf::Color(230, 230, 230), 110, 22);
  _drawCenterText("A French", sf::Color(230, 230, 230), 140, 16);
  _drawCenterText("An Arab", sf::Color(230, 230, 230), 160, 16);
  _drawCenterText("A stephanois", sf::Color(230, 230, 230), 180, 16);
  txt.setStyle(sf::Text::Bold);
  _drawCenterText("Press ENTER to play ...", sf::Color(248, 168, 0), 215, 18);
  txt.setStyle(sf::Text::Regular);
  _drawMenu(s.games, 0, "GAMES");
  _drawMenu(s.graphics, _window->getSize().x/2, "GRAPHICS");

  _window->display();
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
