# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 18:36:36 by mzomeno-          #+#    #+#              #
#    Updated: 2021/04/19 23:36:09 by mzomeno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP	= push_swap
CHECKER = checker

TEST	= test

CC = gcc
SHELL = sh
CFLAGS += -g -Wall -Wextra -Werror

INCLUDE_DIR = include/
HEADERS = $(shell find $(INCLUDE_DIR) -name "*.h")

LIBFT = libft.a
LIBFT_DIR = libft/

GNL_DIR = get_next_line
# SRC_GNL = $(shell find $(GNL_DIR) -name  "*.c" | xargs -I % $(SHELL) -c 'echo % | cut -c 15-')

SRC_DIR = src
SRC_CHECKER = $(shell find $(SRC_DIR) -name  "*.c" | xargs -I % $(SHELL) -c 'echo % | cut -c 5-')

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_CHECKER:.c=.o))

all: $(PUSH_SWAP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(CHECKER): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT_DIR)$(LIBFT) $(CFLAGS) -o $(CHECKER)

$(PUSH_SWAP): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT_DIR)$(LIBFT) $(CFLAGS) -o $(PUSH_SWAP)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
	mkdir $(OBJ_DIR)/common
	mkdir $(OBJ_DIR)/push_swap
#	mkdir $(OBJ_DIR)/checker
	mkdir $(OBJ_DIR)/args_cooker
	mkdir $(OBJ_DIR)/instructions
	mkdir $(OBJ_DIR)/bonus
	mkdir $(OBJ_DIR)/$(GNL_DIR)

$(LIBFT): $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR) re

clean:
		@rm -rf $(OBJ_DIR)/
		@$(MAKE) -C $(LIBFT_DIR) fclean

fclean:		clean
		@rm -f $(CHECKER) $(PUSH_SWAP)
		@echo Objects and executable file erased, bye!

re: fclean all
