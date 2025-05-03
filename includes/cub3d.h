
#ifndef CUB3D_H
# define cub3D_H

# define WIDTH 1280
# define HEIGHT 720

# include "minilibx/mlx.h"
# include "get_next_line_bonus.h"
# include "libft/libft.h"
# include <X11/X.h>      //for masks and event name
# include <X11/keysym.h> //for keys macros
# include <fcntl.h>      //readonlymacro
# include <math.h>

typedef struct s_batata
{
	void	*mlx;
	void	*window;
	void	*img;

	char *pixels;
    int bpp;
    int size_line;
    int endian;

}t_game;

void init_game(t_game *game);
void	draw_square(int x, int y, int size, int color, t_game *game);

#endif