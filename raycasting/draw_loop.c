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
void dda_init(t_game *game)
{
	game->player.plane_x = game->player.dir_y;
	game->player.plane_y = 0.66; //not sure

	int x;

	x = 0;
	while(x < WIDTH)
	{
		game->dda->camerax = 2 * x / (double)WIDTH - 1;
		game->dda->rayDirX = game->player.dir_x + game->dda->camerax * game->player.plane_x;
		game->dda->rayDiry = game->player.dir_y + game->dda->camerax * game->player.plane_y;

	}
	

}
int draw_loop(t_game *game)
{
	move_player(&(game->player));
	
	clear_image(game);
	draw_2d_map(game);

		//missing ray loop range
		// t_optic_ray aux = send_optic_ray(game->player.x, game->player.y, game->player.angle, game->map.buffer, game);
		// printf("aux ray dist: %d\n", aux.dist);
	    // bresenham(aux.start_x, aux.start_y, aux.start_x + aux.dist, aux.start_y + aux.dist, game ) ;
		mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);

    return 1;
}