# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/08 15:07:52 by svelhinh          #+#    #+#              #
#    Updated: 2017/07/10 18:22:59 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++

CFLAGS = -g -Wall -Wextra -Werror --std=c++11 -fPIC

LIBFLAGS = -lncurses -shared -fPIC

NAME = libncurses.so

SRC = Graphics.cpp

INCLUDES = -I../../includes

OBJ = $(SRC:.cpp=.o)

ifneq ($(shell uname), Linux)
SHELL = ZSH
endif

all: $(NAME)
	@echo -n "\033[0m"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $@ $(LIBFLAGS)

%.o: %.cpp
	@echo -n "\033[94m"
	@echo $<
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@echo "\033[91mNcurses library objs deleted\033[0m"
	@rm -rf $(OBJ)

fclean: clean
	@echo "\033[91mNcurses library deleted\033[0m"
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
