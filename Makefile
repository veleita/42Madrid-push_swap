# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 18:36:36 by mzomeno-          #+#    #+#              #
#    Updated: 2021/05/11 18:13:56 by mzomeno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SHELL = sh
CFLAGS += -g -Wall -Wextra -Werror

INCLUDE_DIR = include/
HEADERS = $(shell find $(INCLUDE_DIR) -name "*.h")


SRC_DIR = src
OBJ_DIR = obj


LIBFT = libft.a
LIBFT_DIR = libft/


CHECKER = checker
CHECKER_DEPENDENCIES = 	$(SRC_DIR)/checker \
						$(SRC_DIR)/args_cooker \
						$(SRC_DIR)/common \
						$(SRC_DIR)/get_next_line \
						$(SRC_DIR)/instructions \
						$(SRC_DIR)/bonus

SRC_CHECKER = $(shell find $(CHECKER_DEPENDENCIES) -name  "*.c" | xargs -I % $(SHELL) -c 'echo % | cut -c 5-')

OBJS_CHECKER = $(addprefix $(OBJ_DIR)/, $(SRC_CHECKER:.c=.o))


PUSH_SWAP	= push_swap
PUSH_SWAP_DEPENDENCIES = 	$(SRC_DIR)/push_swap \
							$(SRC_DIR)/common \
							$(SRC_DIR)/args_cooker \
							$(SRC_DIR)/instructions \
							$(SRC_DIR)/bonus

SRC_PUSH_SWAP = $(shell find $(PUSH_SWAP_DEPENDENCIES) -name  "*.c" | xargs -I % $(SHELL) -c 'echo % | cut -c 5-')

OBJS_PUSH_SWAP = $(addprefix $(OBJ_DIR)/, $(SRC_PUSH_SWAP:.c=.o))


all: $(PUSH_SWAP) $(CHECKER)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(CHECKER): $(OBJ_DIR) $(OBJS_CHECKER) $(LIBFT_DIR)$(LIBFT)

	$(CC) $(OBJS_CHECKER) $(LIBFT_DIR)$(LIBFT) $(CFLAGS) -o $(CHECKER)

$(PUSH_SWAP): $(OBJ_DIR) $(OBJS_PUSH_SWAP) $(LIBFT_DIR)$(LIBFT)
	$(CC) $(OBJS_PUSH_SWAP) $(LIBFT_DIR)$(LIBFT) $(CFLAGS) -o $(PUSH_SWAP)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
	mkdir $(OBJ_DIR)/common
	mkdir $(OBJ_DIR)/push_swap
	mkdir $(OBJ_DIR)/checker
	mkdir $(OBJ_DIR)/args_cooker
	mkdir $(OBJ_DIR)/instructions
	mkdir $(OBJ_DIR)/bonus
	mkdir $(OBJ_DIR)/get_next_line

$(LIBFT_DIR)$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	

clean:
		@rm -rf $(OBJ_DIR)/
		@$(MAKE) -C $(LIBFT_DIR) fclean

fclean:		clean
		@rm -f $(CHECKER) $(PUSH_SWAP)
		@echo Objects and executable file erased, bye!

re: fclean all
