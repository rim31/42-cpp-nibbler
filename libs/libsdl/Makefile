# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/08 15:07:52 by svelhinh          #+#    #+#              #
#    Updated: 2017/07/10 18:23:04 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libsdl.so
FLAG    = -g -Wall -Werror -Wextra -fPIC

CLASS	= Graphics
FILES	= $(CLASS)
SRCS	= $(addsuffix .cpp, $(FILES))

OBJS	= $(SRCS:.cpp=.o)
INC		= ../../includes/
INCS    = -I $(INC) -I ./SDL2-2.0.5/include
LIBS    = ./glew/lib/libGLEW.a -lGL ./sdl2/lib/libSDL2.a -lX11 -lXxf86vm -lpthread -ldl -lXrandr -lXinerama -lXcursor -lXi
FRAM    = -framework OpenGl -framework Cocoa -framework ImageCaptureCore -framework IOKit -framework Carbon -framework CoreVideo -framework CoreAudio -framework AudioUnit -framework CoreAudioKit -framework CoreMIDI -framework ForceFeedback -framework CoreFoundation -framework AudioToolbox ./glew/lib/libGLEW.a ./sdl2/lib/libSDL2.a -liconv
GLEW    = glew
GLM     = glm
SDL2    = SDL2-2.0.5
OS		= $(shell uname)
CPPV    = -std=c++11

all:$(NAME)

$(NAME): | libs $(OS)

Darwin: $(OBJS)
	clang++ $(FLAG) -o $(NAME) $^ $(FRAM) -shared

Linux: $(OBJS)
	clang++ $(FLAG) -o $(NAME) $^ $(LIBS)

%.o:%.cpp
	clang++ $(CPPV) $(FLAG) $(INCS) -o $@ -c $< -fPIC

libs: $(GLEW)
	if ! [ -f ./glew/lib/libGLEW.a ]; then \
		make -C $(GLEW) extensions; \
		make -C $(GLEW); \
	fi
	if ! [ -f ./sdl2/lib/libSDL2.a ]; then \
		cd $(SDL2); touch configure.ac aclocal.m4 configure Makefile.am Makefile.in ; ./configure --prefix=$(shell pwd)/sdl2 ; make ; make install ; \
	fi

$(GLEW): | $(GLM)
	git clone https://github.com/nigels-com/glew.git

$(GLM): | $(SDL2)
	git clone https://github.com/g-truc/glm.git

$(SDL2):
	curl -o sdl.tar https://www.libsdl.org/release/SDL2-2.0.5.tar.gz && tar -xf sdl.tar && rm -rf sdl.tar

clean:
	@echo "\033[91mSDL library objs deleted\033[0m"
	@rm -rf $(OBJS)

fclean: clean
	@echo "\033[91mSDL library deleted\033[0m"
	@rm -rf sdl2 glew glm sdl.tar $(SDL2)
	@rm -rf $(NAME)

fcleansdl:
	@rm -rf $(NAME)

resdl: fcleansdl all

re: fclean all

.PHONY: clean fclean re all libs Linux Darwin
