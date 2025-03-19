#include "get_next_line.h"

void	ft_delete_node(t_list **p_head, int fd)
{
	t_list	*prev;
	t_list	*curr;

	prev = NULL;
	curr = *p_head;
	while (curr != NULL)
	{
		if (curr->fd == fd)
		{
			if (prev)
				prev->next = curr->next;
			else
				*p_head = curr->next;
			free(curr->str_buf);
			free(curr);
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}

t_list	*get_or_create_node(t_list **p_head, int fd)
{
	t_list	*node;

	node = *p_head;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->fd = fd;
	node->str_buf = ft_strdup("");
	node->next = *p_head;
	*p_head = node;
	return (node);
}


char	*ft_read_line(t_list *p_head, t_list *node, int fd)
{
	ssize_t			bts_rd;

	bts_rd = read(node->fd, node->str_buf, BUFFER_SIZE);
	if (bts_rd == -1 || (bts_rd == 0 && node->str_buf[0] == '\0'))
	{
		ft_delete_node(&p_head, fd);
		return (NULL);
	}
	
	return (NULL);
}

char	*get_next_line(int fd)
{
	ssize_t			bts_rd;
	static t_list	*p_head;
	t_list			*node;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	node = get_or_create_node(&p_head, fd);
	if (node == NULL)
		return (NULL);
	bts_rd = read(0, node->str_buf, 0);
	if (bts_rd == -1)
		return (NULL);
	return ("ft_read_line(p_head, node, fd)");	
	// return (ft_read_line(p_head, node, fd));	
}
