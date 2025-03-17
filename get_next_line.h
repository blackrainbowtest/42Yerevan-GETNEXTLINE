#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				fd;
	char			*str_buf;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
t_list	*get_or_create_node(t_list	**p_head, int fd);
void	ft_delete_node(t_list **p_head, int fd);

#endif
