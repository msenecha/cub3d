# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 16:11:32 by msenecha          #+#    #+#              #
#    Updated: 2024/01/05 16:11:35 by msenecha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################ SOURCES ################################

SRC_DIR = ./sources/

SRC	=	main.c color_txtr_errors.c control_direction.c control_player_move.c\
		control_player_position.c control_player_rotation.c dir_file_errors.c\
		engine.c errors_msg.c events.c exit.c frame.c free.c get_file_data.c\
		init.c map_errors.c map_size_errors.c map.c mlx_init.c parsing.c\
		txtr_errors.c txtr_init.c txtr_render.c utils_img.c utils.c


OBJS	=	${addprefix ${SRC_DIR}, $(SRC:.c=.o)}


################################ LIBFT ################################

LIBFT_DIR	=	./libft/
LIBFT_PATH	=	${LIBFT_DIR}libft.a


################################ MINILIBX ################################

MLX_DIR		=	./minilibx_linux/
MLX_PATH	=	${MLX_DIR}libmlx.a


################################ ARGUMENTS ################################

NAME	=	cub3d

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g
MFLAGS	=	-ldl -lmlx -L${MLX_DIR} -lm -lXext -lX11 -Imlx $(MLX_PATH)
IFLAGS	=	-I ./includes
LFLAGS	=	-L $(LIBFT_DIR) -lft

RM		=	rm -f


################################ RULES ################################

all: $(NAME)

$(NAME): libft mlx $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LFLAGS) -o $(NAME) $(MFLAGS)
		@$(MAKE) clean

%.o:	%.c
		@$(CC) $(CFLAGS) -c $< -o $@

.SILENT:
libft:
		@$(MAKE) -C $(LIBFT_DIR)

.SILENT:
mlx:
		@$(MAKE) -C $(MLX_DIR)

clean:
		@$(MAKE) -C $(LIBFT_DIR) clean
		@$(MAKE) -C $(MLX_DIR) clean
		@$(RM) $(OBJS)

fclean: clean
		@$(RM) $(LIBFT_PATH)
		@$(RM) $(MLX_PATH)
		@$(RM) $(NAME)

re:
		@$(MAKE) fclean
		@$(MAKE) all

.PHONY: all libft mlx clean fclean re
