#include "../includes/cub3d.h"

int is_wall_hit_cord(float x, float y,  char **map)
{

	if (map[(int)floor(y + DEVIATION)] 
		 && map[(int)floor(y + DEVIATION)][(int)floor(x + DEVIATION)] == '1')
		return(1);
  	if (map[(int)floor(y + DEVIATION)] 
		 && map[(int)floor(y + DEVIATION)][(int)floor(x)] == '1')
		return(1);
	return 0;
}
// int is_ray_hit(float x, float y,  char **map, t_2D increase)
// {
// 	if (y + increase.y < 0 || x + increase.x < 0)
// 		return (1);
// 	if (map[(int)floor(y + increase.y)] 
// 		 && map[(int)floor(y + increase.y)][(int)floor(x + increase.x)] == '1')//TOP LEFT colision
// 		return(1);
// 	if (map[(int)floor(y + increase.y)] 
// 	 	&& (map[(int)floor(y + DEVIATION + increase.y)][(int)floor(x + increase.x)] == '1'))//DOWN LEFT colision
// 		return(1);
// 	if (map[(int)floor(y + increase.y)]
// 		&& (map[(int)floor(y + DEVIATION + increase.y)][(int)floor(x + DEVIATION + increase.x)] == '1'))//BOTOM RIGHT colision
// 		return(1);
// 	if (map[(int)floor(y + increase.y )]
// 		&& (map[(int)floor(y + DEVIATION + increase.y)][(int)floor(x + increase.x)] == '1'))//BOTOM LEFT colision
// 		return(1);

// 	return 0;

// }

t_optic_ray send_optic_ray(float player_x, float player_y, float ori, char **map, t_game *game)
{

  t_2D increase;
  t_optic_ray ray;

  ray.start_x = player_x ;
  ray.start_y = player_y;
  ray.dist = 0;
  
  increase.x = -cos(ori);
  increase.y = -sin(ori);

  printf("SEND OPTIC: player_x: %f, player_y: %f\n, ori: %f\n", player_x, player_y, ori);
    while(!is_wall_hit_cord(ray.start_x + increase.x, ray.start_y + increase.y, map))
    {
      ray.dist += 0.1;
      ray.start_x+= increase.x * 0.1;
      ray.start_y+= increase.y * 0.1;
      put_point(ray.start_x * TILE_SIZE, ray.start_y * TILE_SIZE, 0x00FFFF00, game);
    }
    // missing implement max dist
    printf ("ray_x: %f, ray_y: %f, dist: %i\n ", ray.start_x, ray.start_y, ray.dist);

    return(ray);
}

void	put_point(int x, int y, int color, t_game *game)
{
	put_pixel( x,  y, color, game);
  put_pixel( x + 1, y, color, game);
  put_pixel( x, y + 1, color, game);
  put_pixel( x + 1,  y + 1, color, game);
  put_pixel( x - 1, y - 1, color, game);
  put_pixel( x -1, y, color, game);
  put_pixel( x,  y -1, color, game);
  put_pixel( x+1, y-1, color, game);
  put_pixel( x-1, y+1, color, game);
	
}