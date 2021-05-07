# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jitlee <jitlee@student.42.kr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 02:33:55 by jitlee            #+#    #+#              #
#    Updated: 2021/05/08 04:26:41 by jitlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRAME_WORK = -framework OpenGl -framework Appkit
MLX = -lmlxo
LIB = -Lsrcs
MANDATORY = ray_cast_func4
BONUS = ray_cast_func4_b
FILES = border_chk:get_next_line:get_next_line_utils:ft_isdigit:ft_strdup:ft_strtrim:ft_bzero:ft_calloc:ft_strlcpy:ft_strlen:ft_memset:ft_mapcpy:ft_strncmp:ft_strchr:ft_itoa:stack:map_chk:map_chk_func:map_chk_func2:map_chk_func3:ray_cast:ray_cast_func:ray_cast_func2:ray_cast_func3:screenshot:cub3d:

DIR = ./srcs/
JOIN = $(subst :, ,$(addsuffix $(MANDATORY),$(FILES)))
JOIN_B = $(subst :, ,$(addsuffix $(BONUS),$(FILES)))
SRCS = $(addprefix $(DIR), $(addsuffix .c, $(JOIN)))
SRCS_B = $(addprefix $(DIR), $(addsuffix .c, $(JOIN_B)))
OBJS = $(addprefix $(DIR), $(addsuffix .o, $(JOIN)))
OBJS_B = $(addprefix $(DIR), $(addsuffix .o, $(JOIN_B)))

.c .o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(FRAME_WORK) -o $@ $^ $(LIB) $(MLX)

all: $(NAME)

bonus: $(OBJS_B)
	$(CC) $(CFLAGS) $(FRAME_WORK) -o $(NAME) $^ $(LIB) $(MLX)

clean:
	rm -f $(OBJS_B) $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
