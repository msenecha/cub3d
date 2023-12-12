# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svidal <svidal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 15:12:37 by svidal            #+#    #+#              #
#    Updated: 2023/12/12 15:58:37 by svidal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################ SOURCES ################################

SRC_DIR = ./src/

SRC	=	main.c init_struct.c init_struct_2.c init_player.c map.c errors_file_arg.c \
			errors_map.c errors_map_2.c errors_map_utils.c free_and_exit.c mlx.c

OBJS	=	${addprefix ${SRC_DIR}, $(SRC:.c=.o)}


################################ LIBFT ################################

LIBFT_DIR	=	./libft/
LIBFT_PATH	=	${LIBFT_DIR}libft.a


################################ MINILIBX ################################

MLX_DIR		=	./minilibx-linux/
MLX_PATH	=	${MLX_DIR}libmlx.a


################################ ARGUMENTS ################################

NAME	=	cub3d

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address
MFLAGS	=	-ldl -lmlx -L${MLX_DIR} -lm -lXext -lX11 -Imlx $(MLX_PATH)
IFLAGS	=	-I ./includes
LFLAGS	=	-L $(LIBFT_DIR) -lft

RM		=	rm -f


################################ RULES ################################

all: $(NAME)

$(NAME): libft mlx $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LFLAGS) -o $(NAME) $(MFLAGS)

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

