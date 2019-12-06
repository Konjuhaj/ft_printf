# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 12:17:08 by bkonjuha          #+#    #+#              #
#    Updated: 2019/12/06 10:28:43 by bkonjuha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c flags.c libft/*.c

OBJ = $(subst .c,.o,$(SRC))

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
