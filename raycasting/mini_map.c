#include "../includes/cub3d.h"


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
                color = 0xFFFFFF;
            else
                color = 0x000000;

			draw_tile(x, y, color, game);
        }
    }
	draw_tile((int)floorf(game->player.x),(int)floorf(game->player.y), 0x00FF00, game);
}
