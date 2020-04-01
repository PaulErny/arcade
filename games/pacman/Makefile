NAME	= games_arcade_pacman.so

CXX	= g++

RM	= rm -f

SRCS	= 

OBJS	= $(SRCS:=.o)

CFLAGS = -I 
CFLAGS += -Wall -Wextra
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
