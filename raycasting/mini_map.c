#include "../includes/cub3d.h"

float	mod(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

//this ft projects the 2 3d points to be conected and
// puts ech point correctly in the image that will be projected in window
// step var determines the frequence each temporary coordinate needs
// to be updated

void	ft_bresenham(t_2D	pos0,	t_2D	pos1, t_game *game)
{
	float	x_step;
	float	y_step;
	float	max;

	x_step = (pos1.x - pos0.x);
	y_step = (pos1.x - pos1.y);
	if (mod(x_step) > mod(y_step))
		max = mod(x_step);
	else
		max = mod(y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(pos0.x - pos1.x) || (int)(pos0.y - pos1.y))
	{
		put_pixel(pos0.x, pos0.y, 0x00FF00 , game);
		pos0.x += x_step;
		pos0.y += y_step;
	}
}
//this fuc connects each point that is not part of a wall to
//the following point; also puts the builted image in the window

void	ft_draw_2D_map(t_game *game)
{
	t_2D	pos0;
	t_2D	pos1;

	pos0.y = 0;
	while (pos0.y < game->map.height)
	{
		pos0.x = 0;
		while (pos0.x < game->map.width)
		{
			if (pos0.x < game->map.width - 1)
			{
				pos1.x = pos0.x + 1.01;
				pos1.y = pos0.y;
				ft_bresenham(pos0, pos1, game);
			}
			if (pos0.y < game->map.height - 1)
			{
				pos1.x = pos0.x;
				pos1.y = pos0.y + 1.01;
				ft_bresenham(pos0, pos1, game);
			}
			pos0.x++;
		}
		pos0.y++;
	}
	printf("aaaaaaaaaaaaaaa\n");
}