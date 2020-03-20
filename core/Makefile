NAME	= arcade

CXX	= g++

RM	= rm -f

SRCS	= ./Core.cpp \
	  		./main.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./pp
override CXXFLAGS = -std=c++17 -Wall -Wextra

LDFLAGS = -ldl

all: $(NAME)

$(NAME): $(OBJS)
	 $(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)
	 mv arcade ../

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
