# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jongkim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/18 18:56:27 by jongkim           #+#    #+#              #
#    Updated: 2020/10/14 14:56:26 by jongkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = ft_write.s \
	   ft_strlen.s \
	   ft_strcpy.s \
	   ft_strcmp.s \
	   ft_read.s \
	   ft_strdup.s

OBJS = $(SRCS:.s=.o)

%.o		: %.s
		nasm -f macho64 $< -o $@

$(NAME) : $(OBJS)
		ar rc $(NAME) $(OBJS)

all : $(NAME)

clean :
		rm -rf $(OBJS)
fclean : clean
		rm -rf $(NAME)

re : fclean all
