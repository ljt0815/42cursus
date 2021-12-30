# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 20:40:21 by jitlee            #+#    #+#              #
#    Updated: 2021/12/30 20:45:16 by jitlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie

CLANG = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

FILES = main		\
		Zombie		\
		ZombieHorde

SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

.cpp.o: $(SRCS)
	@$(CLANG) $(CXXFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@$(CLANG) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : clean all

.PHONY: all clean fclean re
