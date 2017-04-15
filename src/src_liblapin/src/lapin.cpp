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

void Lapin::displayMenu(const t_info_menu &s) const
{
  t_bunny_picture *img_games[3];
  t_bunny_picture *img_libs[4];
  t_bunny_position pos[2];

  (void)s;
  pos[0].x = 50;
  pos[0].y = 50;
  pos[1].x = 330;
  pos[1].y = 50;
  color_full(_pix, BLACK);
  img_games[0] = bunny_load_picture("src/src_liblapin/src/cadre-jeux.png");
  img_games[1] = bunny_load_picture("src/src_liblapin/src/cadre-Scheck.png");
  img_games[2] = bunny_load_picture("src/src_liblapin/src/cadre-Pcheck.png");
  img_libs[0] = bunny_load_picture("src/src_liblapin/src/cadre-lib.png");
  img_libs[1] = bunny_load_picture("src/src_liblapin/src/cadre-Lapincheck.png");
  img_libs[2] = bunny_load_picture("src/src_liblapin/src/cadre-SFMLcheck.png");
  img_libs[3] = bunny_load_picture("src/src_liblapin/src/cadre-Ncursescheck.png");
  bunny_blit(&_win->buffer, &_pix->clipable, 0);
  bunny_blit(&_win->buffer, img_games[0], &pos[0]);
  bunny_blit(&_win->buffer, img_libs[0], &pos[1]);
  bunny_display(_win);
  for (unsigned int i = 0; i < s.games.size(); i++)
    {
      std::cout << "Value: " << s.games[i].value << "\nChecked: " << s.games[i].checked << "\nPointed: " << s.games[i].pointed << std::endl;
    }
  for (unsigned int i = 0; i < s.graphics.size(); i++)
    {
      std::cout << "Value: " << s.graphics[i].value << "\nChecked: " << s.graphics[i].checked << "\nPointed: " << s.graphics[i].pointed << std::endl;
    }
  for (int i = 0; i < 4; i++)
    {
      if (i < 3)
	bunny_delete_clipable(img_games[i]);
      bunny_delete_clipable(img_libs[i]);
    }
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
