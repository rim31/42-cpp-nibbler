# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/08 15:07:52 by svelhinh          #+#    #+#              #
#    Updated: 2017/07/10 18:23:26 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++

CFLAGS = -g -Wall -Wextra -Werror --std=c++11

LIBFLAGS = -ldl -rpath $(SFMLPATH)/SFML/lib

NCURSESPATH = libs/libncurses/

SDLPATH = libs/libsdl/

SFMLPATH = libs/libsfml/

BIN_DIR = bin

NAME = $(BIN_DIR)/nibbler

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
	@mkdir -p $(BIN_DIR)
	@make -C $(NCURSESPATH)
	@make -C $(SDLPATH)
	@make -C $(SFMLPATH)
	@$(CC) $(OBJ) -o $@ $(LIBFLAGS)

%.o: %.cpp
	@echo -n "\033[94m"
	@echo $<
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

resdl:
	@make resdl -C $(SDLPATH)

resfml:
	@make resfml -C $(SFMLPATH)

clean:
	@make clean -C $(NCURSESPATH)
	@make clean -C $(SDLPATH)
	@make clean -C $(SFMLPATH)
	@echo "\033[91mNibbler objs deleted\033[0m"
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C $(NCURSESPATH)
	@make fcleansdl -C $(SDLPATH)
	@make fcleansfml -C $(SFMLPATH)
	@echo "\033[91mNibbler deleted\033[0m"
	@rm -rf $(BIN_DIR)

fcleanall: clean
	@make fclean -C $(NCURSESPATH)
	@make fclean -C $(SDLPATH)
	@make fclean -C $(SFMLPATH)
	@echo "\033[91mNibbler deleted\033[0m"
	@rm -rf $(BIN_DIR)

reall: fcleanall all

re: fclean all

.PHONY: clean fclean re all reall fcleanall cleanall resdl resfml
