NAME	= program

CXX	= g++

RM	= rm -f

SRCS	= ./main.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I 
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = -ldl

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) $(LDFLAGS) -o $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
