#include "../includes/cub3d.h"

int	ft_handle_close_win(t_game *game)
{
	//int	i;

	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	// i = 0;
	// while (data->z_matrix[i])
	// {
	// 	free(data->z_matrix[i]);
	// 	i++;
	// }
	// if (data->z_matrix)
	// 	free(data->z_matrix);
	exit(0);
	return (0);
}

void	ft_event_hooks(t_game *game)
{
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask,
		ft_handle_close_win, game);

		mlx_hook(game->window, KeyPress, KeyPressMask, ft_key_press, game);
		mlx_hook(game->window, KeyRelease, KeyReleaseMask, ft_key_release,
			game);
}

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->player.key_up = true;
	if (keycode == XK_s)
		game->player.key_down = true;
	if (keycode == 97)
	{
		game->player.key_left = true;
	}
	if (keycode == XK_d)
		game->player.key_right = true;
	if (keycode == XK_Left)
		game->player.left_rotate = true;
	if (keycode == XK_Right)
		game->player.right_rotate = true;
	return (0);
}

int	ft_key_release(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->player.key_up = false;
	if (keycode == XK_s)
		game->player.key_down = false;
	if (keycode == 97)
	{
		game->player.key_left = false;
	}
	if (keycode == XK_d)
		game->player.key_right = false;
	if (keycode == XK_Left)
		game->player.left_rotate = false;
	if (keycode == XK_Right)
		game->player.right_rotate = false;
	if (keycode == XK_Escape)
		ft_handle_close_win(game);
	return (0);
}
