#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <sys/mman.h>

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

#endif
