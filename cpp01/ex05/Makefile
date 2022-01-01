# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/01 23:15:30 by jitlee            #+#    #+#              #
#    Updated: 2022/01/02 00:08:14 by jitlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Karen

CLANG = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

FILES = main	\
		Karen

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
