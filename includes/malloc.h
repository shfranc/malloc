#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <sys/mman.h>
# include <sys/resource.h>
# include <pthread.h>
# include <fcntl.h>

# define NB_BLOCKS		100
# define TINY_BLOCK		512
# define SMALL_BLOCK	4096

# define STAT			1
# define LOG			1

# define STAT_FILE		"metrics"
# define LOG_FILE		"logs"



typedef struct 		s_block
{
	size_t				size;
	struct s_block		*prev;
	struct s_block		*next;
}						t_block;

typedef struct s_heap
{
	t_block				*in_use;
	t_block				*free;
}						t_heap;

t_heap					g_heap[2];
extern pthread_mutex_t 	g_mutex;

enum e_heap
{
	TINY,
	SMALL,
	LARGE
};

enum e_lib
{
	MALLOC,
	FREE,
	REALLOC,
	CALLOC
};

void		*malloc(size_t size);
void		*calloc(size_t count, size_t size);
void		free(void *ptr);
void		*realloc(void *ptr, size_t size);
void		show_alloc_mem(void);
void		show_alloc_mem_hex(void);

/*
** FREE POOL
*/
t_block		*ft_choose_free_block(int type, size_t size);
t_block 	*ft_add_free_block(t_block *last, int type, size_t size);
t_block		*ft_extend_free_pool(void *last, int type, size_t size);
t_block		*ft_request_memory(void *last, size_t size);
void		ft_move_block_to_use(int type, t_block *block);

/*
** IN USE POOL
*/
int 		ft_find_used_block(void *ptr, t_block **block);
void		ft_move_block_to_free(int type, t_block *block);

/*
** FREE
*/
void		ft_free_block(int type, t_block *block);
void		ft_defragmentation(int type);

/*
** BLOCKS
*/
t_block		*ft_split_block(t_block *block, int type, size_t size);
void		ft_delete_block(t_block **start, t_block *block);
void		ft_insert_block_top(t_block **start, t_block *block);
void		ft_insert_block_top_defrag(t_block **start, t_block *block);
int			ft_insert_block_addr(t_block **start, t_block *new_block);

/*
** TOOLS
*/
size_t 		ft_align_size(size_t size, size_t multiple);
size_t		ft_header_size(void);

/*
** STATS
*/
void		ft_stat_malloc(int i);
void		ft_stat_free(void);
void		ft_stat_defrag(void);

/*
** LOGS
*/
void		ft_log(int f, t_block *block);

/*
** DISPLAY
*/
void		ft_show_heap(t_block *blocks);
void		ft_putnbr(int n);
void		ft_putnbr_fd(int fd, int n);
void		ft_putnbr_endl(int n);
void		ft_putullnbr_endl(unsigned long long int n);
void		ft_putnbr_str(char *str, int n);
void		ft_putchar(char c);
void		ft_putchar_fd(int fd, char c);
void		ft_putstr(char const *s);
void		ft_putstr_fd(int fd, char const *s);
void		ft_putendl(char const *s);
void		ft_putendl_2(char const *s1, char const *s2);
void		ft_putaddr(unsigned long long p);
void		ft_putaddr_fd(int fd, unsigned long long p);
void		ft_putaddr_endl(unsigned long long p);
void		ft_print_memory(const void *addr, size_t size);

#endif
