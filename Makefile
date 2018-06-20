ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc.so
LIB = libft_malloc_$(HOSTTYPE).so

PATH_SRCS = srcs
PATH_OBJS = objs
PATH_INC = includes
PATH_LIB = $(shell pwd)

SRCS = $(addprefix $(PATH_SRCS)/, malloc.c show_alloc_mem.c free_pool.c block.c display_str.c display_nbr.c ft_putaddr.c ft_align_size.c )
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

TEST = test

all: $(NAME)

$(NAME): $(LIB)
	@ln -s $^ $@
	@echo "$(PINK)link:$(RESET)\t$@"

$(TEST): $(LIB) srcs/main.c
	@$(CC) -o $@ srcs/main.c -I $(PATH_INC) $(LIB)
	@echo "$(WHITE)test:$(RESET)\t$@"

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
	@rm -rf $(TEST)
	@echo "$(BLUE)clean:$(RESET)\t$(TEST)"

re: fclean all

.PHONY: clean fclean re
