NAME	= program

MAKE: 
	make -C ./SDL/
	make -C ./SFML/
	make -C ./Ncurses/

RM	= rm -f

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./pp
CXXFLAGS = -Wall -Wextra

all: MAKE

clean:
	make clean -C ./SDL/
	make clean -C ./SFML/
	make clean -C ./Ncurses/

fclean:
	make fclean -C ./SDL/
	make fclean -C ./SFML/
	make fclean -C ./Ncurses/

re: 
	make re -C ./SDL/
	make re -C ./SFML/
	make re -C ./Ncurses/

.PHONY: all clean fclean re
