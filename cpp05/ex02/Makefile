# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 14:53:42 by jitlee            #+#    #+#              #
#    Updated: 2022/02/13 10:17:33 by jitlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CLANG = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

FILES = main					\
		Bureaucrat				\
		ShrubberyCreationForm	\
		Form


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
