# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 12:07:48 by mstaali           #+#    #+#              #
#    Updated: 2023/12/06 23:21:26 by mstaali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAIN_SOURCES = ft_printf.c Utility/ft_putstr.c Utility/ft_putchar.c Utility/ft_putptr_hexa.c Utility/ft_putnbr.c \
	Utility/ft_putnbr_unsigned.c Utility/ft_putnbr_hexalower.c Utility/ft_putnbr_hexaupper.c Bonus/ft_checksecflags.c

MAIN_OBJECTS = $(MAIN_SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(MAIN_OBJECTS)
	ar rcs $(NAME) $(MAIN_OBJECTS)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus : all

clean :
	rm -f $(MAIN_OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean