#include "../includes/cub3d.h"

void	ft_event_hooks(t_game *game)
{
	//mlx_hook(game->window, DestroyNotify, StructureNotifyMask,
	//	ft_handle_close_win, game);

	    printf("AAAAAAAAAAAa\n");
	mlx_hook(game->window, KeyPress, KeyPressMask, ft_key_press, game);
	mlx_hook(game->window, KeyRelease, KeyReleaseMask, ft_key_release,
		game);
}

int	ft_key_press(int keycode, t_player *player)
{
	if (keycode == XK_w)
		player->key_up = true;
	if (keycode == XK_s)
		player->key_down = true;
	if (keycode == 97)
	{
		printf("left\n");
		player->key_left = true;
	}
	if (keycode == XK_d)
		player->key_right = true;
	if (keycode == XK_Left)
		player->left_rotate = true;
	if (keycode == XK_Right)
		player->right_rotate = true;
	return (0);
}

int	ft_key_release(int keycode, t_player *player)
{
	if (keycode == XK_w)
		player->key_up = false;
	if (keycode == XK_s)
		player->key_down = false;
	if (keycode == 97)
	{
		printf("stop left\n");
		player->key_left = false;
	}
	if (keycode == XK_d)
		player->key_right = false;
	if (keycode == XK_Left)
		player->left_rotate = false;
	if (keycode == XK_Right)
		player->right_rotate = false;
	return (0);
}
