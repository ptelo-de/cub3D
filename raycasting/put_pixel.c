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

void	draw_square(t_2D pos, int size, int color, t_game *game)
{
	int	i;
	int	x;
	int	y;

	x = (int)pos.x;
	y = (int)pos.y;
	i = -1;
	while (++i < size)
		put_pixel(x + i, y, color, game);
	i = -1;
	while (++i < size)
		put_pixel(x, y + i, color, game);
	i = -1;
	while (++i < size)
		put_pixel(x + size, y + i, color, game);
	i = -1;
	while (++i < size)
		put_pixel(x + i, y + size, color, game);
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
    move_player(game->player,3, 0.03);
    clear_image(game);
    draw_square(game->player->pos, 10, 0x00FF00, game);
    mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
    return 0;
}