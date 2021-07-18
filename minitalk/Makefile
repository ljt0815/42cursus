# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 13:08:10 by jitlee            #+#    #+#              #
#    Updated: 2021/07/18 06:34:23 by marvin           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

S_NAME = server
C_NAME = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAG = -I
LIBFT_F = ./libft
LIBFT = libft.a
RM = rm -f

S_FILES =	server	\
			util
C_FILES =	client	\
			util

LIBFT_A = -L$(LIBFT_F) -lft

S_SRCS = $(addsuffix .c, $(S_FILES))
S_OBJS = $(addsuffix .o, $(S_FILES))

C_SRCS = $(addsuffix .c, $(C_FILES))
C_OBJS = $(addsuffix .o, $(C_FILES))

all: $(LIBFT) $(S_NAME) $(C_NAME)

$(LIBFT):
	make -C $(LIBFT_F)

$(S_NAME): $(S_OBJS)
	$(CC) $(CFLAGS) $(IFLAG)$(LIBFT_F) $(S_OBJS) $(LIBFT_A) -o $(S_NAME)

$(C_NAME): $(C_OBJS)
	$(CC) $(CFLAGS) $(IFLAG)$(LIBFT_F) $(C_OBJS) $(LIBFT_A) -o $(C_NAME)

%.o: %.c $(LIBFT_F)/libft.h
	$(CC) $(CFLAGS) -c $< $(IFLAG) $(LIBFT_F)
#.c.o: 
#	$(CC) $(CFLAGS) $(IFLAG)$(LIBFT_F) -c -o $(S_OBJS) $(S_SRCS)
#	$(CC) $(CFLAGS) $(IFLAG)$(LIBFT_F) -c -o $(C_OBJS) $(C_SRCS)

clean:
	$(RM) $(S_OBJS) $(C_OBJS)
	make -C $(LIBFT_F) clean

fclean: clean
	$(RM) $(S_NAME) $(C_NAME)
	make -C $(LIBFT_F) fclean

re: clean all

.PHONY: all clean fclean re
