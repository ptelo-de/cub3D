#include "../includes/cub3d.h"

int **get_map(void)
{
    const char *src[] = {
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

    int **map = malloc(sizeof(int *) * 11);
    for (int i = 0; i < 10; i++) {
        map[i] = malloc(sizeof(int) * 15);
        for (int j = 0; j < 15; j++)
            map[i][j] = src[i][j] - '0';
    }
    map[10] = NULL;
    return map;
}

int main(void)
{
	t_game game;

	init_game(&game);
	ft_event_hooks(&game);

	mlx_loop_hook(game.mlx, draw_loop, &game);

	mlx_loop(game.mlx);

}