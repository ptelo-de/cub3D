#include "../includes/cub3d.h"

char **get_map(void)
{
    static char *src[] = {
        "111111111111111", 
		"100000000000001", 
		"100000000000001",
        "100000100000001", 
		"100000000000001", 
		"100000010000001",
        "100001000000001", 
		"100000000000001", 
		"100000000000001",
        "111111111111111", NULL
    };
    return src;
}

void init_game(t_game *game)
{
	init_player(&game->player);
	game->map.buffer = get_map();
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIDTH, HEIGHT, \
	"Cub3D by bde-luce and ptelo-de");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->pixels = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
}
