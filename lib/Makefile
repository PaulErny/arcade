NAME	= program

MAKE: 
	make -C ./SDL/
	make -C ./SFML/

RM	= rm -f

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./pp
CXXFLAGS = -Wall -Wextra

all: MAKE

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
