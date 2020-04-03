CXX	= g++

NAME	= lib_arcade_pacman.so
NAMETWO = lib_arcade_nibbler.so

RM	= rm -f

MAKE:
	make -C ./nibbler/
	make -C ./pacman/

SRCS	= ./Entity.cpp \

OBJS	= $(SRCS:=.o)

override CFLAGS = -I 
override CXXLAGS += -Wall -Wextra
override LDFLAGS = -std=c++17 -fPIC -shared

all: $(NAME)
	MAKE

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	make clean -C ./nibbler/
	make clean -C ./pacman/
	$(RM) $(NAME) $(NAMETWO)

fclean:
	make fclean -C ./nibbler/
	make fclean -C ./pacman/
	$(RM) $(NAME) $(NAMETWO)

re: 
	$(RM) $(NAME) $(NAMETWO)
	make re -C ./nibbler/
	make re -C ./pacman/

.PHONY: all clean fclean re
