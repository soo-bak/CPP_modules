NAME = replace
COMPILER = clang++
CFLAGS = -Wall -Wextra -Werror
CPP_VERSION = -std=c++03
SRCS = main.cpp \
	Replacer.cpp \

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
	@./$(NAME)

.PHONY: all clean fclean re
