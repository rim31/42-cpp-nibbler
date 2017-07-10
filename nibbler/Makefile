# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/08 15:07:52 by svelhinh          #+#    #+#              #
#    Updated: 2017/04/12 17:09:54 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++

CFLAGS = -Wall -Wextra -Werror --std=c++11

LIBFLAGS = -ldl

NCURSESPATH = libs/libncurses/

SDLPATH = libs/libsdl/

NAME = nibbler

SRC = main.cpp GraphicsHandler.cpp Game.cpp Snake.cpp

SRCS = $(addprefix srcs/,$(SRC))

INCLUDES = -I./includes

OBJ = $(SRCS:.cpp=.o)

ifneq ($(shell uname), Linux)
SHELL = ZSH
endif

all: $(NAME)
	@echo -n "\033[0m"

$(NAME): $(OBJ)
	@make -C $(NCURSESPATH)
	@make -C $(SDLPATH)
	@$(CC) $(OBJ) -o $@ $(LIBFLAGS)

%.o: %.cpp
	@echo -n "\033[94m"
	@echo $<
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@make clean -C $(NCURSESPATH)
	@make clean -C $(SDLPATH)
	@echo "\033[91mNibbler objs deleted\033[0m"
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C $(NCURSESPATH)
	@make fclean -C $(SDLPATH)
	@echo "\033[91mNibbler deleted\033[0m"
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all rtv
