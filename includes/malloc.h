#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <sys/mman.h>

# define RED		"\033[01;31m"
# define GREEN		"\033[01;32m"
# define YELLOW		"\033[01;33m"
# define BLUE		"\033[01;34m"
# define PINK		"\033[01;35m"
# define CYAN		"\033[01;36m"
# define WHITE		"\033[01;37m"
# define RESET		"\033[00m"

# define BLOCK_SIZE	0x20
# define TINY		0x80 // 128
// # define SMALL		0x80
# define LARGE		0x1000 // 4096

typedef struct s_block {
	size_t				size; /* 8 bytes */
//	struct s_block		*prev; /* 8 bytes */
	struct s_block		*next; /* 8 bytes */
	int					free; /* 4 bytes + padding = 4 bytes */
	void				*data; /* 8 bytes */
}				t_block;

typedef struct s_heap
{
	t_block				*start;
	t_block				*last;
	size_t				total;
	size_t				mapped;
}				t_heap;

typedef struct s_handler
{
	t_heap				*tiny;
	t_heap				*small;
	t_heap				*large;
}				t_handler;

t_heap			g_handler;

void	*malloc(size_t size);
void	*ft_malloc(size_t size);

/*
** HEAP
*/
void	ft_extend_heap(void);
void	ft_print_heap(void);

/*
** BLOCK
*/
void	ft_init_block(t_block *block, size_t size);
void	*ft_find_block(size_t size);
void	*ft_split_block(t_block *last, size_t size);
int		ft_fusion_block(t_block *block1, t_block *block2);
void	ft_print_blocks(t_block *blocks);

/*
** DISPLAY
*/
void	ft_putnbr(int n);
void	ft_putnbr_endl(int n);
void	ft_putnbr_str(char *str, int n);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putendl_2(char const *s1, char const *s2);
void	ft_putaddr(unsigned long long p);

#endif
