# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 14:40:48 by jitlee            #+#    #+#              #
#    Updated: 2021/11/11 15:25:17 by jitlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CLANG = clang++
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

FILES = megaphone

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
