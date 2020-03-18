NAME	= menuNcurses

CC	= g++

RM	= rm -f

SRCS	= ./game.cpp \
	  ./lib.cpp \
	  ./main.cpp 

OBJS	= $(SRCS:.cpp=.o)

LIBFLAGS = -lncurses
CPPFLAGS = -I ./pp
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(LIBFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
