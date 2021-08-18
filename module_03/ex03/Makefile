NAME = ex03
COMPILER = clang++
CFLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow
CPP_VERSION = -std=c++03
SRCS = main.cpp \
	ClapTrap.cpp \
	ScavTrap.cpp \
	FragTrap.cpp \
	DiamondTrap.cpp \

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
