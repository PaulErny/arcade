MAKE:
	make -C ./lib/
	make -C ./core/
	make -C ./games/

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
	make clean -C ./core/
	make clean -C ./games/

fclean:
	make fclean -C ./lib/
	make fclean -C ./core/
	make fclean -C ./games/

re:
	make re -C ./lib/
	make re -C ./core/
	make re -C ./games/

.PHONY: all clean fclean re
