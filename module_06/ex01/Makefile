NAME = ex01
COMPILER = clang++
CFLAGS = -Wall -Wextra -Werror
CPP_VERSION = -std=c++03
SRCS = main.cpp \
	serialize.cpp \
	deserialize.cpp \

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	@$(COMPILER) $(CFLAGS) $(CPP_VERSION) -o $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	@$(COMPILER) $(CFLAGS) $(CPP_VERSION) -c $(SRCS)

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: re
	@./$(NAME) a

.PHONY: all clean fclean re
