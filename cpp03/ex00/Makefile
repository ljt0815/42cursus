# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 12:04:52 by jitlee            #+#    #+#              #
#    Updated: 2022/01/31 12:05:08 by jitlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap

CLANG = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

FILES = main		\
		Fixed


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
