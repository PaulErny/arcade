NAME	= lib_arcade_SDL2.so

CXX	= g++

RM	= rm -f

SRCS	= ./Sdl.cpp 

OBJS	= $(SRCS:.cpp=.o)

MVSO:
	mv lib_arcade_SDL2.so ../

CPPFLAGS = -I ./
override CXXFLAGS = -std=c++17 -Wall -Wextra
override LDLIBS = -lSDL2
override LDFLAGS = -fPIC -shared

all: $(NAME)
	MVSO

$(NAME): $(OBJS)
	 $(CXX) $(LDFLAGS) $(LDLIBS) $(SRCS) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
