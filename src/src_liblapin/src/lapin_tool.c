/*
** lapin_tool.c for lapin_tool in /home/riamon_v/rendu/PSU/PSU_2016_lemipc/bonus/src
** 
** Made by Riamon Vincent
** Login   <riamon_v@epitech.net>
** 
** Started on  Thu Apr  6 10:51:50 2017 Riamon Vincent
** Last update Fri Apr  7 17:15:37 2017 Riamon Vincent
*/

#include "lemipc.h"

void		tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos,
			 unsigned int col)
{
  ((unsigned int *)pix->pixels)[(pix->clipable.clip_width * pos->y)
				+ pos->x] = col;
}

void		color_full(t_bunny_pixelarray *pix, unsigned int col)
{
  unsigned int	*pixels;
  int		i;

  i = -1;
  pixels = pix->pixels;
  while (++i < pix->clipable.buffer.width * pix->clipable.buffer.height)
    pixels[i] = col;
}

void		draw_case(t_bunny_pixelarray *pix, t_bunny_position *pos,
			  t_color *col)
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
	  tekpixel(pix, pos, col->full);
	  pos->x++;
	}
      pos->y++;
    }
  pos->y = save_y;
}
