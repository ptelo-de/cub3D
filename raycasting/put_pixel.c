#include "../includes/cub3d.h"

void put_pixel(int x, int y, int color, t_game *game)
{
    if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return;
    
    int index = y * game->size_line + x * game->bpp / 8;
    game->pixels[index] = color & 0xFF;
    game->pixels[index + 1] = (color >> 8) & 0xFF;
    game->pixels[index + 2] = (color >> 16) & 0xFF;
}
