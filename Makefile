# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 16:53:33 by ptelo-de          #+#    #+#              #
#    Updated: 2025/06/10 20:37:35 by ptelo-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror -g #-gdwarf-4 

RM				=	rm -rf

INC_DIR			=	includes/

OBJ_DIR			=	objs/

GNL_DIR			=	includes/get_next_line/

MLX_PATH		=	includes/minilibx/

LINKS			=  -L./$(MLX_PATH) -lmlx -L./includes/libft -lft -lX11 -lXext -lm -lbsd

SRC				=	raycasting/pilar_main.c \
					raycasting/init_game.c \
					raycasting/draw_loop.c \
					raycasting/player.c \
					raycasting/event_hook.c \
					raycasting/mini_map.c \
					raycasting/optic_ray.c \
					raycasting/bresenham.c
					
SRC_DIR			= raycasting

OBJ				=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o) 

$(NAME):			$(OBJ) | $(SRC)
					make bonus -C includes/libft/
					printf 'Compiling $(NAME)\n'
					$(CC) $(CFLAGS) $^ -o $@ -I $(INC_DIR) $(LINKS) -L ./includes/libft -lft


$(OBJ_DIR)%.o:		$(SRC_DIR)%.c | $(OBJ_DIR)
					make dependecies
					printf "Compiling $(NAME) objects... %-33.33s\r" $(notdir $@)
					$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) 

$(OBJ_DIR):
					mkdir -p $@

all:				$(NAME)

dependecies:
					make -C $(MLX_PATH)

clean:
					if [ -d $(OBJ_DIR) ]; then $(RM) $(OBJ_DIR); fi
					cd $(MLX_PATH) && make clean
					cd includes/libft && make clean


fclean:				clean
					$(RM) $(NAME)
					cd includes/libft && make fclean


re:					fclean all

.PHONY:				all clean fclean re
