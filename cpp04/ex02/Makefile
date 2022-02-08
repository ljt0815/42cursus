# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 05:23:26 by jitlee            #+#    #+#              #
#    Updated: 2022/02/08 01:38:32 by jitlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CLANG = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

FILES = main		\
		Animal		\
		Dog			\
		Cat			\
		Brain


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
