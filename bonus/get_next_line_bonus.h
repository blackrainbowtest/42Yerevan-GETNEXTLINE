#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/*
* BUFFER_SIZE: size of the buffer to read the file
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/*
* MAX_OPEN: maximum number of file descriptors
*/
# ifndef MAX_OPEN
#  define MAX_OPEN 256
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

/*
* fd: file descriptor
* str_buf: buffer to store the read line
* next: pointer to the next node
*/
typedef struct s_list
{
	int				fd;
	char			*str_buf;
	struct s_list	*next;
}				t_list;

/*
* get_next_line_utils_bonus.c
*/
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_first_line(char *s1);
char	*ft_remove_read_line(char *s1);

/*
* get_next_line_bonus.c
*/
void	ft_delete_node(t_list **p_head, int fd);
t_list	*get_or_create_node(t_list **p_head, int fd);
char	*ft_read_line(t_list *p_head, t_list *node, int fd);
char	*get_next_line(int fd);
#endif