#include "../includes/cub3d.h"

void	player_first_pos(t_player *player, t_game *game)
{
	int x;
	int y;

	y = 0;
	x = 0;
    while (game->map.buffer[y])
	{
		if (game->map.buffer[y][x] == 'N')
			break;
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
	printf("x: %f y: %f\n", player->x, player->y);
}

void	init_player(t_player *player, t_game *game)
{

	player_first_pos(player, game);
	player->angle = 3.14 / (float)(2);

	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;

	player->left_rotate = false;
	player->right_rotate = false;
}

void	set_angle(t_player *player, float angle_speed)
{
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}
void	move_player(t_player *player, int speed, float angle_speed)
{
	float	cos_angle;
	float	sin_angle;

	set_angle(player, angle_speed);
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->key_up)
	{
		player->x -= cos_angle * speed;
		player->y -= sin_angle * speed;
	}
	if (player->key_down)
	{
		player->x += cos_angle * speed;
		player->y += sin_angle * speed;
	}
	if (player->key_left)
	{
		player->x -= sin_angle * speed;
		player->y += cos_angle * speed;
	}
	if (player->key_right)
	{
		player->x += sin_angle * speed;
		player->y -= cos_angle * speed;
	}
}
