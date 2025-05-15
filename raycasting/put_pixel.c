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

int draw_loop(t_game *game)
{
	move_player(&(game->player),0.1, 0.03);
    clear_image(game);
	draw_2d_map(game);
	//t_2D pos;
	// pos.x = game->player.x;
	// pos.y = game->player.y;
	// draw_square(pos, 10, 0x00FF00,game);
    mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
    return 0;
}