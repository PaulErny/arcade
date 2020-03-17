NAME	= lib_arcade_SFML.so

CXX	= g++

RM	= rm -f

SRCS	= ./SFMLLib.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./
override CXXFLAGS = -std=c++17
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
