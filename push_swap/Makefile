# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 13:08:10 by jitlee            #+#    #+#              #
#    Updated: 2021/05/24 12:58:27 by marvin           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAG = -I
LIBFT_F = ./libft

FILES = push_swap		\
		push_swap_func	\
		listnode		\
		merge_sort
LIBFT_A = -L$(LIBFT_F) -lft
SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
RM = rm -f

OBJS_DIR = ./srcs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) $(IFLAG)$(LIBFT_F) -c -o $@ $<

$(NAME): $(OBJS)
	make -C $(LIBFT_F)
	$(CC) $(CFLAGS) $(IFLAG)$(LIBFT_F) $(OBJS) $(LIBFT_A) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)
	make -C $(LIBFT_F) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_F) fclean

re: clean all

.PHONY: all clean fclean re
