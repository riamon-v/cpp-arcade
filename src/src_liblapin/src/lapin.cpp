//
// lapin.cpp for lapin in /home/riamon_v/rendu/CPP/cpp_arcade/src/src_liblapin/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Mon Apr 10 20:52:22 2017 Riamon Vincent
// Last update Fri Apr 14 23:25:54 2017 Riamon Vincent
//

#include "Llapin.hpp"

Lapin::Lapin()
{
  _inputs[BKS_2] = PREV_LIB;
  _inputs[BKS_3] = NEXT_LIB;
  _inputs[BKS_4] = PREV_GAME;
  _inputs[BKS_5] = NEXT_GAME;
  _inputs[BKS_8] = RESTART;
  _inputs[BKS_9] = MENU;
  _inputs[BKS_ESCAPE] = EXIT;
  _inputs[BKS_RIGHT] = RIGHT;
  _inputs[BKS_LEFT] = LEFT;
  _inputs[BKS_UP] = UP;
  _inputs[BKS_DOWN] = DOWN;
  _inputs[BKS_RETURN] = PLAY;
  _in = UNDEFINED;
  _arcade = bunny_load_picture("src/src_liblapin/images/arcade.png");
  _menu = bunny_load_picture("src/src_liblapin/images/menu.png");
  _menuS = bunny_load_picture("src/src_liblapin/images/menuS.png");
  _pictures["pacman"] = bunny_load_picture("src/src_liblapin/images/pacman.png");
  _pictures["pacmanS"] = bunny_load_picture("src/src_liblapin/images/pacmanS.png");
  _pictures["snake"] = bunny_load_picture("src/src_liblapin/images/snake.png");
  _pictures["snakeS"] = bunny_load_picture("src/src_liblapin/images/snakeS.png");
  _pictures["nibbler"] = bunny_load_picture("src/src_liblapin/images/nibbler.png");
  _pictures["nibblerS"] = bunny_load_picture("src/src_liblapin/images/nibblerS.png");
  _pictures["ncurses"] = bunny_load_picture("src/src_liblapin/images/ncurses.png");
  _pictures["ncursesS"] = bunny_load_picture("src/src_liblapin/images/ncursesS.png");
  _pictures["sfml"] = bunny_load_picture("src/src_liblapin/images/sfml.png");
  _pictures["sfmlS"] = bunny_load_picture("src/src_liblapin/images/sfmlS.png");
  _pictures["lapin"] = bunny_load_picture("src/src_liblapin/images/lapin.png");
  _pictures["lapinS"] = bunny_load_picture("src/src_liblapin/images/lapinS.png");
  configure(WIN_W, WIN_H);
}

Lapin::~Lapin()
{
  kill();
}

int Lapin::configure(unsigned int width, unsigned int height)
{
  _win = bunny_start(width, height, 0, "Arcade : LibLapin");
  _pix = bunny_new_pixelarray(width, height);
  bunny_blit(&_win->buffer, &_pix->clipable, 0);
  bunny_display(_win);
  return (0);
}

void Lapin::display(std::vector<TileInfo> const &_tiles) const
{
  t_bunny_position pos = {.x = 0, .y = 0};
  t_color col;

  for (int i = 0; i < MAP_W * MAP_H; i++)
    {
      if (i != 0 && !(i % MAP_W))
	{
	  pos.x = 0;
	  pos.y += WIN_H / MAP_H;
	}
      col.full = _tiles[i].color.hexacode;
      draw_case(&pos, &col);
      pos.x += MAP_W / WIN_W;
    }
  bunny_blit(&_win->buffer, &_pix->clipable, 0);
  bunny_display(_win);
}

void Lapin::drawMenu(const std::vector<t_value_menu> &tab, const unsigned int begin) const{
  t_bunny_position p;

  if (tab[0].checked)
  {
      p.x = begin;
      p.y = 160;
      if (_menuS || _menu)
        bunny_blit(&_win->buffer, _menuS ? _menuS : _menu, &p);
  }
  else if (_menuS)
  {
    p.x = begin;
    p.y = 160;
    if (_menu)
      bunny_blit(&_win->buffer, _menu, &p);
  }

  for (size_t i = 0; i < tab.size(); i++) {
    if (tab[i].value.find_last_of("_") != std::string::npos &&
        tab[i].value.find_last_of(".") != std::string::npos)
      {
        unsigned int f = tab[i].value.find_last_of("_");
        std::string pict = tab[i].value.substr(f + 1,
                                            tab[i].value.find_last_of(".") - f - 1);
        if (tab[i].pointed)
          pict = pict + 'S';
        try {
          t_bunny_picture *tmp;
          tmp = _pictures.at(pict);
          p.x = 31 + begin;
          p.y = 190 + i * 100;
          bunny_blit(&_win->buffer, tmp, &p);
        } catch (const std::exception &c) {
          std::cerr << "don't found " << pict << " image"<< '\n';
        }
      }
  }
}

void Lapin::displayMenu(const t_info_menu &s) const
{
  color_full(_pix, 0x303130);
  bunny_blit(&_win->buffer, &_pix->clipable, 0);
  if (_arcade)
  {
    t_bunny_position p;
    p.x = 150;
    p.y = 0;
    bunny_blit(&_win->buffer, _arcade, &p);
  }
  drawMenu(s.games, 20);
  drawMenu(s.graphics, 300);
  bunny_display(_win);
}

t_bunny_response Lapin::pseudo_events(t_bunny_event_state st,
				      t_bunny_keysym key, void *ptr)
{
  (void)ptr;
  if (st == GO_DOWN && bunny_get_keyboard()[key])
    _in = _inputs[key];
  else
    _in = UNDEFINED;
  return (GO_ON);
}

t_bunny_response Lapin::pseudo_loop(void *d)
{
  (void)d;
  return (EXIT_ON_SUCCESS);
}

Input Lapin::getInputs() const
{
  bunny_set_loop_main_function(pseudo_loop);
  bunny_set_key_response((t_bunny_key)&pseudo_events);
  bunny_loop(_win, 100, NULL);
  return (_in);
}

void Lapin::kill()
{
  bunny_stop(_win);
}

void		Lapin::tekpixel(t_bunny_position *pos, unsigned int col) const
{
  ((unsigned int *)_pix->pixels)[(_pix->clipable.clip_width * pos->y)
				+ pos->x] = col;
}

void		Lapin::color_full(t_bunny_pixelarray *pix, unsigned int col) const
{
  unsigned int	*pixels;
  int		i;

  i = -1;
  pixels = (unsigned int *)pix->pixels;
  while (++i < pix->clipable.buffer.width * pix->clipable.buffer.height)
    pixels[i] = col;
}

void		Lapin::draw_case(t_bunny_position *pos, t_color *col) const
{
  int		i;
  int		j;
  int		save_x;
  int		save_y;

  save_x = pos->x;
  save_y = pos->y;
  i = -1;
  while (++i < (WIN_H / MAP_H))
    {
      j = -1;
      pos->x = save_x;
      while (++j < (WIN_W / MAP_W))
	{
	  tekpixel(pos, col->full);
	  pos->x++;
	}
      pos->y++;
    }
  pos->y = save_y;
}

IDisplay *cln::clone()
{
  return new Lapin;
}
