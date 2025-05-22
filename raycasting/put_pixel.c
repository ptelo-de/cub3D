#include "../includes/cub3d.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->pixels[index] = color & 0xFF;
	game->pixels[index + 1] = (color >> 8) & 0xFF;
	game->pixels[index + 2] = (color >> 16) & 0xFF;
}

void	clear_image(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while ( ++x < WIDTH)
			put_pixel(x, y, 0, game);
	}
}


int is_wall_hit_2(t_player player)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(player.angle);
	sin_angle = sin(player.angle);
	if (player.key_up)
	{
		player.x -= cos_angle * SPEED;
		player.y -= sin_angle * SPEED;
	}
	if (player.key_down)
	{
		player.x += cos_angle * SPEED;
		player.y += sin_angle * SPEED;
	}
	if (player.key_left)
	{
		player.x -= sin_angle * SPEED;
		player.y += cos_angle * SPEED;
	}
	if (player.key_right)
	{
		player.x += sin_angle * SPEED;
		player.y -= cos_angle * SPEED;
	}
	
	if (player.y < 0 || player.x < 0)
		return 1;

	return 0;
}


int is_wall_hit(t_player player ,float to_move_x, float to_move_y)
{
	if (player.map[(int)(player.y + to_move_y)] 
		 && player.map[(int)(player.y + to_move_y)][(int)(player.x + to_move_x)] == '1')//TOP LEFT colision
	{
		return(1);
	}
	if (player.map[(int)floor(player.y + to_move_y)] 
	 	&& (player.map[(int)floor(player.y + DEVIATION + to_move_y)][(int)floor(player.x + to_move_x)] == '1'))//DOWN LEFT colision
	{
		return(1);
	}
	if (player.map[(int)floor(player.y + to_move_y)]
		&& (player.map[(int)floor(player.y + DEVIATION + to_move_y)][(int)floor(player.x + DEVIATION + to_move_x)] == '1'))//BOTOM RIGHT colision
	{
		return(1);
	}
	if (player.map[(int)floor(player.y + to_move_y )]
		&& (player.map[(int)floor(player.y + DEVIATION + to_move_y)][(int)floor(player.x + to_move_x)] == '1'))//BOTOM LEFT colision
	{
		return(1);
	}

	return 0;
}

int draw_loop(t_game *game)
{
		move_player(&(game->player));
		clear_image(game);
		draw_2d_map(game);
		mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);

    return 1;
}