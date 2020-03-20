NAME	= lib_arcade_sfml.so

CXX	= g++

RM	= rm -f

SRCS	= ./SFMLLib.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./
override CXXFLAGS = -std=c++17
override LDLIBS = -lsfml-system -lsfml-graphics -lsfml-window
override LDFLAGS = -fPIC -shared

all: $(NAME)
	mv lib_arcade_SFML.so ../

$(NAME): $(OBJS)
	 $(CXX) $(LDFLAGS) $(LDLIBS) $(SRCS) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
