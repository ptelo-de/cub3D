#include "../includes/cub3d.h"

void	init_map(t_map	*map)
{
	map->height = 4;
	map->width = 5;
}

void init_game(t_game *game)
{
	init_player(&game->player);
	init_map(&game->map);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIDTH, HEIGHT, \
	"Cub3D by bde-luce and ptelo-de");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->pixels = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
}
