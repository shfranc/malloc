#include "malloc.h"

static void	ft_print_log_line(int fd, char *s, t_block *block)
{
	ft_putstr_fd(fd, s);
	ft_putstr_fd(fd, "\t- ");
	ft_putaddr_fd(fd, (unsigned long long)block);
	if (block)
	{
		ft_putstr_fd(fd, " ** ");		
		ft_putaddr_fd(fd, (unsigned long long)((char*)block + ft_header_size()));
		ft_putstr_fd(fd, " - ");
		ft_putaddr_fd(fd, (unsigned long long)((char*)block + ft_header_size() + block->size));
		ft_putstr_fd(fd, " : ");
		ft_putnbr_fd(fd, block->size);
		ft_putstr_fd(fd, " octets -");
		ft_putstr_fd(fd, " prev : ");
		ft_putaddr_fd(fd, (unsigned long long)block->prev);
		ft_putstr_fd(fd, " next : ");
		ft_putaddr_fd(fd, (unsigned long long)block->next);
	}
	ft_putchar_fd(fd, '\n');
}

void	ft_log(int f, t_block *block)
{
	int	fd;

	fd = open(LOG_FILE, O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		return ;
	if (f == REALLOC)
		ft_putstr_fd(fd, "realloc: ");
	else if (f == CALLOC)
		ft_putstr_fd(fd, "calloc: ");
	else if (f == MALLOC)
		ft_print_log_line(fd, "malloc", block);
	else if (f == FREE)
		ft_print_log_line(fd, "free", block);
	close(fd);	
}