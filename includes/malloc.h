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

# define BLOCK_SIZE	(8 * 4)

typedef struct 		s_block
{
	size_t			size;
	size_t			free;
	void			*data;
	struct s_block	*next;
}					t_block;

typedef struct s_heap
{
	t_block		*tiny;
	t_block		*small;
	t_block		*large;
	t_block		*last;
	size_t		max;
}				t_heap;

t_heap		g_heap;


void	*malloc(size_t size);
void	*ft_malloc(size_t size);

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
