# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 18:07:56 by mrios-he          #+#    #+#              #
#    Updated: 2024/03/21 11:46:29 by mrios-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a

SRCS = ft_printf.c ft_puthexadecimal.c ft_putpointer.c ft_putnbr.c ft_putstr.c \
       ft_putchar.c ft_putunbr.c ft_atoi.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
