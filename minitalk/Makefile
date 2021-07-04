# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 13:08:10 by jitlee            #+#    #+#              #
#    Updated: 2021/07/05 01:47:28 by jitlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S_NAME = server
C_NAME = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAG = -I
LIBFT_F = ./libft
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

all: $(S_NAME) $(C_NAME)

$(S_NAME): $(S_OBJS)
	make -C $(LIBFT_F)
	$(CC) $(CFLAGS) $(IFLAG)$(LIBFT_F) $(S_OBJS) $(LIBFT_A) -o $(S_NAME)

$(C_NAME): $(C_OBJS)
	make -C $(LIBFT_F)
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
