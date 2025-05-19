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
void	init_square(t_square *square, t_player player)
{
	square->v1.x = player.x -  TILE_SIZE;
	square->v3.x = player.x -  TILE_SIZE;
	square->v2.x = player.x + TILE_SIZE;
	square->v4.x = player.x + TILE_SIZE;
	square->v1.y = player.y + TILE_SIZE;
	square->v2.y = player.y + TILE_SIZE;
	square->v3.y = player.y - TILE_SIZE;
	square->v4.y = player.y - TILE_SIZE;
}

int is_wall_hit(t_player player, char **map, float speed, float angle_speed)
{
	t_player player2 = player;
	float	cos_angle;
	float	sin_angle;

	set_angle(&player2, angle_speed);
	cos_angle = cos(player2.angle);
	sin_angle = sin(player2.angle);
	if (player2.key_up)
	{
		player2.x -= cos_angle * speed;
		player2.y -= sin_angle * speed;
	}
	if (player2.key_down)
	{
		player2.x += cos_angle * speed;
		player2.y += sin_angle * speed;
	}
	if (player2.key_left)
	{
		player2.x -= sin_angle * speed;
		player2.y += cos_angle * speed;
	}
	if (player2.key_right)
	{
		player2.x += sin_angle * speed;
		player2.y -= cos_angle * speed;
	}
	
	if (player2.y< 0 || player2.x < 0|| map[(int)player2.y + 1][(int)player2.x + 1] == '1'){
		printf("x = %f | y = %f | map = %c\n", player2.x, player2.y, map[(int)player2.y][(int)player2.x]);
		printf("x = %f | y = %f | map = %c\n", player.x, player.y, map[(int)player.y][(int)player.x]);
		return 1;
	}
	return 0;
}
int draw_loop(t_game *game)
{
	t_square square;
	// move_player(&(game->player),0.1, 0.03);
	init_square(&square, game->player);
	if (is_wall_hit(game->player, game->map.buffer, 0.05, 0.03) == 0)
	{
		move_player(&(game->player),0.1, 0.03);
		clear_image(game);
		draw_2d_map(game);
		mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
	}

	// printf("v1: (%f, %f)\n", square.v1.x, square.v1.y);
	// printf("v2: (%f, %f)\n", square.v2.x, square.v2.y);
	// printf("v3: (%f, %f)\n", square.v3.x, square.v3.y);
	// printf("v4: (%f, %f)\n", square.v4.x, square.v4.y);

    return 1;
}