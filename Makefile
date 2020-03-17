NAME	= program

CXX	= g++

RM	= rm -f

OBJS	= $(SRCS:.cpp=.o)

MAKE:
	make -C ./lib/

graphicals:
	make -C ./lib/

games:
	make -C ./games/

core:
	make -C ./core/

CPPFLAGS = -I ./lib/pp
CPPFLAGS += -Wall -Wextra

all: MAKE

clean:
	make clean -C ./lib/

fclean:
	make fclean -C ./lib/

re:
	make re -C ./lib/

.PHONY: all clean fclean re
