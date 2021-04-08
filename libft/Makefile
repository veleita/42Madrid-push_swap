# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 17:17:04 by mzomeno-          #+#    #+#              #
#    Updated: 2021/04/08 18:23:22 by mzomeno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a


CC		=	gcc
SHELL	=	sh

CFLAGS	+=	-Werror -Wall -Wextra

AR		=	ar -rcs


SRC		=	$(shell find . -name  "*.c" | xargs -I % $(SHELL) -c 'echo % | cut -c 3-')

OBJS	 =	 $(SRC:%.c=%.o)

all:	$(NAME)

$(NAME): $(OBJS) libft.h
			$(AR) $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
			rm -rf $(OBJS) $(OBJ_BONUS)

fclean: clean
			rm -rf $(NAME)

re: fclean all
