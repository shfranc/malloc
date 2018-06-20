#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <sys/mman.h>
# include <sys/resource.h>

# define RED		"\033[01;31m"
# define GREEN		"\033[01;32m"
# define YELLOW		"\033[01;33m"
# define BLUE		"\033[01;34m"
# define PINK		"\033[01;35m"
# define CYAN		"\033[01;36m"
# define WHITE		"\033[01;37m"
# define RESET		"\033[00m"

# define NB_BLOCKS		100
# define TINY_BLOCK		512
# define SMALL_BLOCK	4096

typedef struct 		s_block
{
	size_t			size;
	struct s_block	*prev;
	struct s_block	*next;
}					t_block;

typedef struct s_heap
{
	t_block		*used;
	t_block		*free;
}				t_heap;

t_heap		g_heap[2];

enum e_heap
{
	TINY,
	SMALL,
	LARGE
};


void		*malloc(size_t size);
void		*ft_malloc(size_t size);

/*
** POOLS
*/
int			ft_choose_pool(size_t size);
t_block		*ft_choose_free_block(int type, size_t size);
t_block		*ft_extend_free_pool(void *last, int type, size_t size);
void		*ft_request_memory(void *last, size_t size);

/*
** BLOCKS
*/
size_t		ft_header_size(void);
void		ft_move_block_to_use(int type, t_block *block);

/*
** TOOLS
*/
size_t 		ft_align_size(size_t size, size_t multiple);

/*
** DISPLAY
*/
void	show_alloc_mem(void);
void	ft_putnbr(int n);
void	ft_putnbr_endl(int n);
void	ft_putullnbr_endl(unsigned long long int n);
void	ft_putnbr_str(char *str, int n);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putendl_2(char const *s1, char const *s2);
void	ft_putaddr(unsigned long long p);
void	ft_putaddr_endl(unsigned long long p);

#endif
