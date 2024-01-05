# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 16:53:40 by svidal            #+#    #+#              #
#    Updated: 2024/01/05 14:27:41 by msenecha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################ SOURCES ################################

SRCS	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
    ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
    ft_memmove.c ft_memset.c ft_split.c ft_strdup.c ft_strjoin.c \
    ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
    ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_putchar_fd.c \
    ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_striteri.c ft_strmapi.c \
    get_next_line.c get_next_line_utils.c \
    ft_printf.c ft_print_c_s_%_d_i_u.c ft_print_x_X.c ft_print_p.c ft_itoa_unsigned.c \
    ft_lstnew.c ft_lstsize.c ft_lstadd_front.c ft_lstadd_back.c \
    ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS	=	$(SRCS:.c=.o)


################################ ARGUMENTS ################################

NAME	=	libft.a

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g

RM	=	rm -f


################################ RULES ################################

all:	$(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
