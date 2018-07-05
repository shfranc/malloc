ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc.so
LIB = libft_malloc_$(HOSTTYPE).so

PATH_SRCS = srcs
PATH_OBJS = objs
PATH_INC = includes
PATH_LIB = $(shell pwd)

SRCS = $(addprefix $(PATH_SRCS)/, malloc.c \
		free.c \
		realloc.c \
		calloc.c \
		show_alloc_mem.c \
		show_alloc_mem_hex.c \
		stats.c \
		logs.c \
		in_use_pool.c \
		free_pool.c \
		block.c \
		defragmentation.c \
		display_str.c \
		display_nbr.c \
		ft_putaddr.c \
		ft_print_memory.c \
		ft_align_size.c )
OBJS = $(SRCS:$(PATH_SRCS)/%.c=$(PATH_OBJS)/%.o)
INCLUDES = $(addprefix $(PATH_INC)/, malloc.h )

FLAGS = -Wall -Wextra -Werror -D_REENTRANT
CC = gcc

RED = \033[01;31m
GREEN = \033[01;32m
YELLOW = \033[01;33m
BLUE = \033[01;34m
PINK = \033[01;35m
CYAN = \033[01;36m
WHITE = \033[01;37m
RESET = \033[00m

MAIN = main

TESTS = tests

all: $(NAME)

$(NAME): $(LIB)
	@ln -s $^ $@
	@echo "$(PINK)link:$(RESET)\t$@"

$(MAIN): $(LIB) srcs/main.c
	@$(CC) -o $@ srcs/main.c -I $(PATH_INC) $(LIB)
	@echo "$(WHITE)test:$(RESET)\t$@"

$(LIB): $(OBJS)
	@$(CC) -shared $^ -o $@  -lpthread
	@echo "$(GREEN)make:$(RESET)\t$@"

$(PATH_OBJS)/%.o: $(PATH_SRCS)/%.c $(INCLUDES)
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(PATH_INC)
	@echo "$(YELLOW)compil:$(RESET)\t$@"

$(TESTS): $(NAME)
	@$(CC) -o test0 test/test0.c
	@echo "$(GREEN)compil:$(RESET)\ttest0"
	@$(CC) -o test1 test/test1.c
	@echo "$(GREEN)compil:$(RESET)\ttest1"	
	@$(CC) -o test2 test/test2.c
	@echo "$(GREEN)compil:$(RESET)\ttest2"
	@$(CC) -o test3 test/test3.c
	@echo "$(GREEN)compil:$(RESET)\ttest3"
	@$(CC) -o test3bis test/test3bis.c
	@echo "$(GREEN)compil:$(RESET)\ttest3bis"
	@$(CC) -o test4 test/test4.c
	@echo "$(GREEN)compil:$(RESET)\ttest4"
	@$(CC) -o test5 test/test5.c -L. -lft_malloc 
	@echo "$(GREEN)compil:$(RESET)\ttest5"
	@$(CC) -o test6 test/test6.c -L. -lft_malloc 
	@echo "$(GREEN)compil:$(RESET)\ttest6"		

clean:
	@rm -rf $(OBJS)
	@rm -rf $(PATH_OBJS)
	@echo "$(BLUE)clean:$(RESET)\t$(OBJS)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(BLUE)clean:$(RESET)\t$(NAME)"
	@rm -rf $(LIB)
	@echo "$(BLUE)clean:$(RESET)\t$(LIB)"
	@rm -rf $(MAIN)
	@echo "$(BLUE)clean:$(RESET)\t$(MAIN)"
	@rm -rf test0 test1 test2 test3 test3bis test4 test5 test6
	@echo "$(BLUE)clean:$(RESET)\t$(TESTS)"	

re: fclean all

.PHONY: clean fclean re

	# gcc state.c -o state -I includes -L . -lft_malloc
