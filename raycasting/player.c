#include "../includes/cub3d.h"

void	init_player(t_player *player)
{
	player = ft_calloc(1, sizeof(t_2D));
	if (!player)
	{
		//free mem
		exit(1);
	}
	player->pos = ft_calloc(1, sizeof(t_2D));
	if (!player->pos)
	{
		//free mem
		exit(1);
	}
	player->pos->x = WIDTH / 2;
	player->pos->y = HEIGHT / 2;
	player->angle = PI / 2;

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
		player->pos->x += cos_angle * speed;
		player->pos->y += sin_angle * speed;
	}
	if (player->key_down)
	{
		player->pos->x -= cos_angle * speed;
		player->pos->y -= sin_angle * speed;
	}
	if (player->key_left)
	{
		player->pos->x += sin_angle * speed;
		player->pos->y -= cos_angle * speed;
	}
	if (player->key_right)
	{
		player->pos->x -= sin_angle * speed;
		player->pos->y += cos_angle * speed;
	}
}
