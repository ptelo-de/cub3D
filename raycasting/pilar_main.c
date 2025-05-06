#include "../includes/cub3d.h"

int **get_map(void)
{
    const char *src[] = {
        "11111", 
		"10001", 
		"10001",
        "11111", NULL
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

    	printf("LLLLLLL\n");
	mlx_loop_hook(game.mlx, draw_loop, &game);

	mlx_loop(game.mlx);

}