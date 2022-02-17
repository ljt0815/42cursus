# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 14:53:42 by jitlee            #+#    #+#              #
#    Updated: 2022/02/18 02:23:20 by jitlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

CLANG = c++
CXXFLAGS = -Wall -Wextra -Werror

RM = rm -f

FILES = main	\
		span


SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

.cpp.o: $(SRCS)
	$(CLANG) $(CXXFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CLANG) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : clean all

.PHONY: all clean fclean re
