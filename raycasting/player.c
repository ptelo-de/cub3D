#include "../includes/cub3d.h"

void	set_angle(t_player *player)
{
	if (player->left_rotate)
		player->angle -= ANGLE_SPEED;
	if (player->right_rotate)
		player->angle += ANGLE_SPEED;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}




int is_wall_hit(t_player player ,float to_move_x, float to_move_y)
{
	if (player.y + to_move_y < 0 || player.x + to_move_x < 0)
		return (1);
	if (player.map[(int)floor(player.y + to_move_y)] 
		 && player.map[(int)floor(player.y + to_move_y)][(int)floor(player.x + to_move_x)] == '1')//TOP LEFT colision
		return(1);
	if (player.map[(int)floor(player.y + to_move_y)] 
	 	&& (player.map[(int)floor(player.y + DEVIATION + to_move_y)][(int)floor(player.x + to_move_x)] == '1'))//DOWN LEFT colision
		return(1);
	if (player.map[(int)floor(player.y + to_move_y)]
		&& (player.map[(int)floor(player.y + DEVIATION + to_move_y)][(int)floor(player.x + DEVIATION + to_move_x)] == '1'))//BOTOM RIGHT colision
		return(1);
	if (player.map[(int)floor(player.y + to_move_y )]
		&& (player.map[(int)floor(player.y + DEVIATION + to_move_y)][(int)floor(player.x + to_move_x)] == '1'))//BOTOM LEFT colision
		return(1);

	return 0;
}

void	wich_direction(t_player player, float *x, float *y)
{
	if(is_wall_hit(player, 0, *y))
		*y = 0;
	if(is_wall_hit(player, *x, 0))
		*x = 0;
}

void	move_player(t_player *player)
{
	float to_move_x;
	float to_move_y;

	if (player->left_rotate || player->right_rotate)
	{
		set_angle(player);
	}
	player->dir_x = cos(player->angle);
	player->dir_y = sin(player->angle);
	
	if (player->key_up)
	{
		to_move_x = -player->dir_x * SPEED;
		to_move_y = -player->dir_y * SPEED;
	}
	if (player->key_down)
	{
		to_move_x = player->dir_x * SPEED;
		to_move_y = player->dir_y * SPEED;
	}
	if (player->key_left)
	{
		to_move_x = -player->dir_y * SPEED;
		to_move_y = player->dir_x * SPEED;
	}
	if (player->key_right)
	{
		to_move_x = player->dir_y * SPEED;
		to_move_y = -player->dir_x * SPEED;
	}
	if (is_wall_hit(*player, to_move_x, to_move_y))
	{
		wich_direction(*player ,&to_move_x, &to_move_y);
	}
	player->x += to_move_x;
	player->y += to_move_y;

}
