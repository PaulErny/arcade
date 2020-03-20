NAME	= lib_arcade_ncurses.so

CXX	= g++

RM	= rm -f

SRCS	= ./NcursesLib.cpp \
			./menu/enterName.cpp \
			./menu/inGame.cpp \
			./menu/inLib.cpp \
			./menu/menu.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./
override CXXFLAGS = -std=c++17
override LDLIBS = -lncurses
override LDFLAGS = -fPIC -shared

all: $(NAME)
	mv lib_arcade_ncurses.so ../

$(NAME): $(OBJS)
	 $(CXX) $(LDFLAGS) $(LDLIBS) $(SRCS) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
