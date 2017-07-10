# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/08 15:07:52 by svelhinh          #+#    #+#              #
#    Updated: 2017/07/10 18:23:08 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++

CFLAGS = -g -Wall -Wextra -Werror --std=c++11 -fPIC

LIBFLAGS = -LSFML/lib -lsfml-graphics -lsfml-window -lsfml-system -shared -fPIC

NAME = libsfml.so

SRC = Graphics.cpp

INCLUDES = -I../../includes -ISFML/include

OBJ = $(SRC:.cpp=.o)

ifneq ($(shell uname), Linux)
SHELL = ZSH
endif

all: | sfml $(NAME)
	@echo -n "\033[0m"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $@ $(LIBFLAGS)	

%.o: %.cpp
	@echo -n "\033[94m"
	@echo $<
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

sfml:
	sh config_sfml.sh

clean:
	@echo "\033[91mSFML library objs deleted\033[0m"
	@rm -rf $(OBJ)

fclean: clean
	@echo "\033[91mSFML library deleted\033[0m"
	@rm -rf SFML
	@rm -rf $(NAME)

fcleansfml: clean
	@echo "\033[91mSFML library deleted\033[0m"
	@rm -rf $(NAME)

resfml: fcleansfml all

re: fclean all

.PHONY: clean fclean re all sfml resfml fcleansfml allall
