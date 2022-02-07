# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 02:54:47 by seuyu             #+#    #+#              #
#    Updated: 2022/02/07 17:35:40 by seuyu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main

CC = c++

CFLAGS = -std=c++98 -Wextra -Werror -Wall

SRCS = main.cpp

OBJS = $(SRCS:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm $(OBJS)

fclean : clean
	rm $(NAME)
re : fclean all

.PHONY : all clean fclean re
