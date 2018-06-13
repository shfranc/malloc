#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <sys/mman.h>

# define BLOCK_SIZE

typedef struct s_block {
	size_t				size; /* 8 bytes */
//	struct s_block		*prev; /* 8 bytes */
	struct s_block		*next; /* 8 bytes */
	int					free; /* 4 bytes + padding = 4 bytes */
	void				*data; /* 8 bytes */
}				t_block;

void	*malloc(size_t size);
void	*ft_malloc(size_t size);


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
