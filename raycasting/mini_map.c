#include "../includes/cub3d.h"

#define TILE_SIZE 10

void draw_tile(int x, int y, int color, t_game *game)
{
	int dx;
	int dy;

	dy = -1;
	while (++dy < TILE_SIZE)
	{
		dx = -1;
		while (++dx < TILE_SIZE)
		{
			put_pixel(x * TILE_SIZE + dx, y * TILE_SIZE + dy, color, game);
		}
	}
}

void	draw_square(t_2D pos, int size, int color, t_game *game)
{
	int	i;
	int	x;
	int	y;

	x = (int)floorf(pos.x);
	y = (int)floorf(pos.y);
		printf("draw_square: x:%d y: %d\n",x,y);
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
void draw_2d_map(t_game *game)
{
    int color;
	int x;
	int y;

	y = -1;
    while (game->map.buffer[++y])
    {
        x = -1;
		while (game->map.buffer[y][++x])
        {
            if (game->map.buffer[y][x] == '1')
                color = 0xFFFFFF; // parede = branco
            else
                color = 0x000000; // chão = preto

			draw_tile(x, y, color, game);
        }
    }
	draw_tile((int)floorf(game->player.x),(int)floorf(game->player.y), 0x00FF00, game);
}
