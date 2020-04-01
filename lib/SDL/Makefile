NAME	= lib_arcade_sdl2.so

CXX	= g++

RM	= rm -f

SRCS	= ./SDLLib.cpp \
			./SDLMenu.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./
override CXXFLAGS = -std=c++17
override LDLIBS = -lSDL2 -lSDL2_ttf -lSDL2_image
override LDFLAGS = -fPIC -shared

all: $(NAME)
	cp $(NAME) ../

$(NAME): $(OBJS)
	 $(CXX) $(LDFLAGS) $(LDLIBS) $(SRCS) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
