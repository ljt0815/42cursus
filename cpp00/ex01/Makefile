# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 14:40:48 by jitlee            #+#    #+#              #
#    Updated: 2021/11/12 04:21:14 by jitlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

CLANG = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

FILES = main		\
		Contact		\
		PhoneBook

SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

.cpp.o: $(SRCS)
	@$(CLANG) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@$(CLANG) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : clean all

.PHONY: all clean fclean re
