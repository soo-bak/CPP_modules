NAME = Account
COMPILER = clang++
CFLAGS = -Wall -Wextra -Werror
CPP_VERSION = -std=c++03
SRCS = Account.cpp \
	tests.cpp \

TESTER = tests.cpp \

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
