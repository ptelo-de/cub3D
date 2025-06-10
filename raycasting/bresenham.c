#include <stdio.h>
#include <math.h>

# include "minilibx/mlx.h"
# include "get_next_line_bonus.h"
# include "libft/libft.h"
# include <X11/X.h>      //for masks and event name
# include <X11/keysym.h> //for keys macros
# include <fcntl.h>      //readonlymacro
# include <math.h>
# include <stdbool.h>
#include "../includes/cub3d.h"
void	put_point(int x, int y, int color, t_game *game);
// Simple plotting function for demonstration
void plot(int x, int y)
{
    printf("Plotting point at (%d, %d)\n", x, y);
}

// Bresenham's Line Drawing Function
void bresenham(int x0, int y0, int x1, int y1, t_game *game)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
	{
		put_point(x0, y0, 0xFF0000 , game);
        plot(x0, y0);  // Plot the current point

        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;

        if (e2 > -dy) // the error is not yet too negative, so it’s safe to move in x
		{
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) // the error is not yet too positive, so it’s safe to move in y
		{
            err += dx;
            y0 += sy;
        }
    }
}
/* 
Think of err as the current accumulated deviation from the ideal line. Every time we move, we're choosing a pixel that’s either:
    Straight horizontally (just change x)
    Diagonally (change both x and y)
The ideal line may fall between pixels. So we track how far off we are from the perfect line. This is where err helps.
It gets larger or smaller based on whether you're falling behind or getting ahead of the perfect line.

This is a decision variable (the "error") used to choose the next pixel:
    -If the error is large in the x-direction, go horizontally
    -If the error is large in the y-direction, go vertically

inclinação (m) = Δy / Δx = (y1 - y0) / (x1 - x0)
------------------------------------------------------------------------------------
	The key reason we double the error value with e2 = 2 * err in Bresenham's 
	algorithm is to avoid using floating-point arithmetic while preserving accurate 
	decision-making about which direction to move — either 
	horizontally, vertically, or both.
---------------------------------------------------------------------------------------
Why -dy?

Because:

    The error grows more negative if we keep going vertically without stepping horizontally
    Once the error gets below -dy, the deviation is too large → time to correct by stepping in x
 */