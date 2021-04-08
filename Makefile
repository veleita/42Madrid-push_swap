# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 18:36:36 by mzomeno-          #+#    #+#              #
#    Updated: 2021/04/08 20:25:21 by mzomeno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

TEST	= test

CC = gcc
SHELL = sh
CFLAGS += -Wall -Wextra -Werror

INCLUDE_DIR = include/
HEADERS = $(shell find $(INCLUDE_DIR) -name "*.h")

LIBFT = libft.a
LIBFT_DIR = libft/

#SRC_DIR = src/
SRC = tests/print_stacks.c src/args_cooker.c src/common/error.c

OBJ_DIR = obj/
OBJS =	$(OBJ_DIR)print_stacks.o \
		$(OBJ_DIR)args_cooker.o \
		$(OBJ_DIR)error.o

all: $(TEST)

$(OBJS): $(SRC)
		$(CC) -g $(CFLAGS) -I $(INCLUDE_DIR) -c tests/print_stacks.c -o $(OBJ_DIR)print_stacks.o
		$(CC) -g $(CFLAGS) -I $(INCLUDE_DIR) -c src/common/error.c -o $(OBJ_DIR)error.o
		$(CC) -g $(CFLAGS) -I $(INCLUDE_DIR) -c src/args_cooker.c -o $(OBJ_DIR)args_cooker.o

$(TEST): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) -g $(OBJS) $(LIBFT_DIR)$(LIBFT) $(CFLAGS) -o $(TEST)

$(OBJ_DIR):
	mkdir obj

$(LIBFT): $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR) re

clean:
		@rm -rf $(OBJ_DIR)
		@$(MAKE) -C $(LIBFT_DIR) fclean

fclean:		clean
		@rm -f $(TEST)
		@echo Objects and executable file erased, bye!

re: fclean all
