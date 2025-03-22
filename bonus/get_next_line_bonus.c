#include "get_next_line_bonus.h"

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
	node->str_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!node->str_buf)
	{
		free(node);
		return (NULL);
	}
	node->str_buf[0] = '\0';
	node->next = *p_head;
	*p_head = node;
	return (node);
}

char	*ft_read_line(t_list *p_head, t_list *node, int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(node->str_buf, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		node->str_buf = ft_strjoin(node->str_buf, buffer);
		if (!node->str_buf)
			break ;
	}
	free(buffer);
	if (bytes_read < 0 || (bytes_read == 0 && (!node->str_buf || !node->str_buf[0])))
	{
		ft_delete_node(&p_head, fd);
		return (NULL);
	}
	return (ft_get_first_line(node->str_buf));
}

char	*get_next_line(int fd)
{
	static t_list	*p_head;
	t_list			*node;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_OPEN)
		return (NULL);
	node = get_or_create_node(&p_head, fd);
	if (node == NULL)
		return (NULL);
	next_line = ft_read_line(p_head, node, fd);
	return (next_line);
}