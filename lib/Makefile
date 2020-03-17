NAME	= program

CC	= make -C ./SDL/

RM	= rm -f

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./pp
CXXFLAGS = -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
