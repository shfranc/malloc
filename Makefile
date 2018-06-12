ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc.so
LIB = libft_malloc_$(HOSTTYPE).so

PATH_SRCS = srcs
PATH_OBJS = objs
PATH_INC = includes

SRCS = $(addprefix $(PATH_SRCS)/, malloc.c )
OBJS = $(SRCS:$(PATH_SRCS)/%.c=$(PATH_OBJS)/%.o)
INCLUDES = $(addprefix $(PATH_INC)/, malloc.h )

FLAGS = -Wall -Wextra -Werror
CC = gcc

RED = \033[01;31m
GREEN = \033[01;32m
YELLOW = \033[01;33m
BLUE = \033[01;34m
PINK = \033[01;35m
CYAN = \033[01;36m
WHITE = \033[01;37m
RESET = \033[00m

all: $(NAME)

$(NAME): $(LIB)
	@ln -s $^ $@
	@echo "$(PINK)link:$(RESET)\t$@"

$(LIB): $(OBJS)
	@$(CC) -shared $^ -o $@
	@echo "$(GREEN)make:$(RESET)\t$@"

$(PATH_OBJS)/%.o: $(PATH_SRCS)/%.c $(INCLUDES)
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(PATH_INC)
	@echo "$(YELLOW)compil:$(RESET)\t$@"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(PATH_OBJS)
	@echo "$(BLUE)clean:$(RESET)\t$(OBJS)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(BLUE)clean:$(RESET)\t$(NAME)"
	@rm -rf $(LIB)
	@echo "$(BLUE)clean:$(RESET)\t$(LIB)"

re: fclean all

.PHONY: clean fclean re
