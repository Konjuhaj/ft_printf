# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 12:17:08 by bkonjuha          #+#    #+#              #
#    Updated: 2019/12/06 11:59:10 by bkonjuha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c flags.c libft/ft_putchar.c

OBJ = *.o #$(subst .c,.o,$(SRC))

.PHONY = all clean fclean re

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) -c $(SRC)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

clean:
		@/bin/rm -f *.o

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all
