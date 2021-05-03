# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 02:33:55 by jitlee            #+#    #+#              #
#    Updated: 2021/05/04 02:25:06 by jitlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRAME_WORK = -framework OpenGl -framework Appkit
MLX_D = libmlx.dylib
FILES = border_chk \
		get_next_line \
		get_next_line_utils \
		ft_isdigit \
		ft_strdup \
		ft_strtrim \
		ft_bzero \
		ft_calloc \
		ft_strlcpy \
		ft_strlen \
		ft_memset \
		ft_mapcpy \
		ft_strncmp \
		ft_strchr \
		stack \
		map_chk \
		map_chk_func \
		map_chk_func2 \
		map_chk_func3 \
		ray_cast \
		ray_cast_func \
		ray_cast_func2 \
		ray_cast_func3 \
		ray_cast_func4 \
		cub3d

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./srcs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(FRAME_WORK) -o $@ $^ -Lsrcs -lmlx 
	mv $(SRCS_DIR)$(MLX_D) ./$(MLX_D)

all: $(NAME)

clean:
	rm -f $(OBJS)
	mv $(MLX_D) $(SRCS_DIR)$(MLX_D)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
