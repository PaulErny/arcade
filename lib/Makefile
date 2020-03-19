NAME	= program

MAKE: 
	make -C ./SDL/
	make -C ./SFML/

RM	= rm -f

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./pp
CXXFLAGS = -Wall -Wextra

all: MAKE
	MVSO

clean:
	make clean -C ./SDL/
	make clean -C ./SFML/

fclean:
	make fclean -C ./SDL/
	make fclean -C ./SFML/

re: 
	make re -C ./SDL/
	make re -C ./SFML/

.PHONY: all clean fclean re
