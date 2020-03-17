NAME	= lib_arcade_SDL2.so

CXX	= g++

RM	= rm -f

SRCS	= ./Sdl.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./
override CXXFLAGS = -std=c++17 -Wall -Wextra
override LDLIBS = -lSDL2
override LDFLAGS = -fPIC -shared

all: $(NAME)

$(NAME): $(OBJS)
	 $(CXX) $(LDFLAGS) $(LDLIBS) $(SRCS) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
