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
char	*ft_read_line(t_list *p_head, t_list *node, int fd);
t_list	*get_or_create_node(t_list	**p_head, int fd);
void	ft_delete_node(t_list **p_head, int fd);
char	*ft_joinstr(const char *s1, const char *s2);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void	ft_strcat(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
