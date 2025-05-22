
#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1280
# define HEIGHT 720

# define PI 3.14159265359
# define SPEED 0.1
# define ANGLE_SPEED 0.03
# define TILE_SIZE 10
# define DEVIATION 0.8


# include "minilibx/mlx.h"
# include "get_next_line_bonus.h"
# include "libft/libft.h"
# include <X11/X.h>      //for masks and event name
# include <X11/keysym.h> //for keys macros
# include <fcntl.h>      //readonlymacro
# include <math.h>
# include <stdbool.h>

typedef struct s_2D
{
	float	x;
	float	y;
}				t_2D;
typedef struct s_square
{
	t_2D v1;
	t_2D v2;
	t_2D v3;
	t_2D v4;
}				t_square;
typedef struct s_player
{
	float	x;
	float	y;
	float	angle;

	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;	
	bool	left_rotate;
	bool	right_rotate;
	char	**map;
}				t_player;

typedef struct s_map
{
	int		height;
	int		width;
	char	**buffer;
}				t_map;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	void		*mlx;
	void		*window;
	void		*img;

	char		*pixels;
	int			bpp;
	int			size_line;
	int			endian;
}	t_game;

//init_game.c
void	init_game(t_game *game);

//put_pixel.c
void	draw_square(t_2D pos, int size, int color, t_game *game);
void	put_pixel(int x, int y, int color, t_game *game);
int 	draw_loop(t_game *game);

//event_hook.c
int		ft_key_press(int keycode, t_game	*game);
int		ft_key_release(int keycode, t_game *game);
void	ft_event_hooks(t_game *game);

//player.c
void	move_player(t_player *player);
void	set_angle(t_player *player);
void	init_player(t_player *player, t_game *game);

//mini_map.c
void draw_2d_map(t_game *game);

int is_wall_hit(t_player player, float y, float x);

#endif