# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 02:33:55 by jitlee            #+#    #+#              #
#    Updated: 2021/05/10 15:02:53 by jitlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRAME_WORK = -framework OpenGl -framework Appkit -framework OpenAl
MLX = -lmlxo
LIB = -Lsrcs
BONUS = ray_cast_func5_b \
		ray_cast_b \
		ft_mapcpy_b \
		ray_cast_func2_b \
		ray_cast_func4_b \
		map_chk_func3_b \
		border_chk_b \
		ray_cast_func6_b

MANDATORY = ray_cast_func5 \
			ray_cast \
			ft_mapcpy \
			ray_cast_func2 \
			ray_cast_func4 \
			map_chk_func3 \
			border_chk

SELECT = MANDATORY
JOIN = $($(SELECT))

FILES = get_next_line \
		get_next_line_utils \
		ft_isdigit \
		ft_strdup \
		ft_strtrim \
		ft_bzero \
		ft_calloc \
		ft_strlcpy \
		ft_strlen \
		ft_memset \
		ft_strncmp \
		ft_strchr \
		ft_itoa \
		stack \
		map_chk \
		map_chk_func \
		map_chk_func2 \
		ray_cast_func \
		ray_cast_func3 \
		screenshot \
		cub3d \
		$(JOIN)


SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./srcs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(FRAME_WORK) -o $@ $^ $(LIB) $(MLX)

all: $(NAME)

bonus :
	make SELECT=BONUS

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
