#include "../includes/cub3d.h"
//BRESENHAM

char **get_map(void)
{
    static char *src[] = {
        "111111111111111", 
		"100000000000001", 
		"100000000000001",
        "100000000000001", 
		"100000000100001", 
		"1000000N0000001",
        "100010000001001", 
		"100000000000001", 
		"100000000000001",
        "111111111111111", NULL
    };
    return src;
}
void init_player_angle(t_player *player, char position)
{
	if (position == 'N')
		player->angle = PI/2;
	if (position == 'W')
		player->angle = PI;
	if (position == 'S')
		player->angle = (3 * PI) / 2;
	if (position == 'E')
		player->angle = 2 * PI;
}
void	player_first_pos(t_player *player, t_game *game)
{
	int x;
	int y;

	y = 0;
	x = 0;
    while (game->map.buffer[y])
	{
		if (game->map.buffer[y][x] == 'N' || game->map.buffer[y][x] == 'S'
		|| game->map.buffer[y][x] == 'W' || game->map.buffer[y][x] == 'E')
		{
			init_player_angle(player, game->map.buffer[y][x]);
			break;
		}
		else if (game->map.buffer[y][x] == '\0')
		{
			x = 0;
			y += 1;
		}
		else
			x++;
	}
	player->x = x;
	player->y = y;
}

void	init_player(t_player *player, t_game *game)
{

	player_first_pos(player, game);
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->left_rotate = false;
	player->right_rotate = false;
	player->map = game->map.buffer;
}

void init_game(t_game *game)
{
	game->map.buffer = get_map();
	init_player(&game->player, game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIDTH, HEIGHT, \
	"Cub3D by bde-luce and ptelo-de");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->pixels = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
}
