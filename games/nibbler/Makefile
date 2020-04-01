NAME	= games_arcade_nibbler.so

CXX	= g++ 

RM	= rm -f

SRCS	= ./Nibbler.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./pp
CPPFLAGS += -Wall -Wextra
override CXXFLAGS = -std=c++17
override LDFLAGS = -fPIC -shared

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
