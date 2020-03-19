NAME	= lib_arcade_SDL2.so

CXX	= g++

RM	= rm -f

SRCS	= ./SDLLib.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./
override CXXFLAGS = -std=c++17
override LDLIBS = -lSDL2
override LDFLAGS = -fPIC -shared

all: $(NAME)
	mv lib_arcade_SDL2.so ../

$(NAME): $(OBJS)
	 $(CXX) $(LDFLAGS) $(LDLIBS) $(SRCS) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
