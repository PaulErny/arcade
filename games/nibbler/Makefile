NAME	= lib_arcade_nibbler.so

CXX	= g++ 

RM	= rm -f

SRCS	= ./Nibbler.cpp \
			../Entity.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./pp
CPPFLAGS += -Wall -Wextra
override CXXFLAGS = -std=c++17
override LDFLAGS = -fPIC -shared

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(LDFLAGS) $(CXXFLAGS) $(SRCS) -o $(NAME)
	 cp $(NAME) ../

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
