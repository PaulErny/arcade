NAME	= lib_arcade_SDL2.so

CC	= g++

RM	= rm -f

SRCS	= ./Sdl.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./pp
CXXFLAGS = -std=c++17 -Wall -Wextra
LIBFLAGS = -lSDL2
DYNLIBFLAGS = -fPIC -shared

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(DYNLIBFLAGS) $(LIBFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
