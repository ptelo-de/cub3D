#include "../includes/cub3d.h"


int main(void)
{
	t_game game;

	init_game(&game);
	ft_event_hooks(&game);

	mlx_loop_hook(game.mlx, draw_loop, &game);

	mlx_loop(game.mlx);

}