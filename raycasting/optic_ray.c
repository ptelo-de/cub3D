#include "../includes/cub3d.h"

// //which box of the map we're in
// int mapX = int(posX);
// int mapY = int(posY);

// //length of ray from current position to next x or y-side
// double deltaDistX, deltaDistY, perpWallDist;

// if (to_move_x == 0.0) {
//     deltaDistX = 1e30;
// } else {
//     deltaDistX = fabs(1.0 / to_move_x);
// }

// if (to_move_to_y == 0.0) {
//     deltaDistY = 1e30;
// } else {
//     deltaDistY = fabs(1.0 / to_move_to_y);
// }

// //length of ray from one x or y-side to next x or y-side

// double perpWallDist;

// //what direction to step in x or y-direction (either +1 or -1)
// double sideDistX;
// double sideDistY;
//       int stepX;
//       int stepY;

//       int hit = 0; //was there a wall hit?
//       int side; //was a NS or a EW wall hit?
// 	        //calculate step and initial sideDist
//       if (to_move_x < 0)
//       {
//         stepX = -1;
//         sideDistX = (posX - mapX) * deltaDistX;
//       }
//       else
//       {
//         stepX = 1;
//         sideDistX = (mapX + 1.0 - posX) * deltaDistX;
//       }
//       if (to_move_to_y < 0)
//       {
//         stepY = -1;
//         sideDistY = (posY - mapY) * deltaDistY;
//       }
//       else
//       {
//         stepY = 1;
//         sideDistY = (mapY + 1.0 - posY) * deltaDistY;
//       }

//       //perform DDA
//       while (hit == 0)
//       {
//         //jump to next map square, either in x-direction, or in y-direction
//         if (sideDistX < sideDistY)
//         {
//           sideDistX += deltaDistX;
//           mapX += stepX;
//           side = 0;
//         }
//         else
//         {
//           sideDistY += deltaDistY;
//           mapY += stepY;
//           side = 1;
//         }
//         //Check if ray has hit a wall
//         if (worldMap[mapX][mapY] > 0) hit = 1;
//       } 
//   //Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
//       if(side == 0) perpWallDist = (sideDistX - deltaDistX);
//       else          perpWallDist = (sideDistY - deltaDistY);

int is_wall_hit_cord(float x, float y,  char **map)
{
	if (y < 0 || x < 0)
		return (1);
	if (map[(int)(y)] 
		 && map[(int)(y)][(int)(x)] == '1')//TOP LEFT colision
		return(1);
	if (map[(int)floor(y)] 
	 	&& (map[(int)floor(y )][(int)floor(x)] == '1'))//DOWN LEFT colision
		return(1);
	if (map[(int)floor(y)]
		&& (map[(int)floor(y)][(int)floor(x)] == '1'))//BOTOM RIGHT colision
		return(1);
	if (map[(int)floor(y )]
		&& (map[(int)floor(y)][(int)floor(x)] == '1'))//BOTOM LEFT colision
		return(1);

	return 0;
}

t_optic_ray send_optic_ray(float x_start, float y_start, float ori, char **map)
{

  t_2D ray;
  t_optic_ray ret;

  ret.x = x_start;
  ret.y = y_start;
  ret.dist = 0;
  ray.x = cos(ori);
  ray.y = sin(ori);

    while(!is_wall_hit_cord(ray.x, ray.y, map))
    {
      ret.dist++;
      ret.x+= ray.x * 0.1;
      ret.y+= ray.y * 0.1;
    }
    return(ret);
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