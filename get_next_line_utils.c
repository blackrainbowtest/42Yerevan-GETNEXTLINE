#include "get_next_line.h"

t_list	*get_or_create_node(t_list	**p_head, int fd)
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
	if (node->str_buf == NULL)
	{
		free(node);
		return (NULL);
	}
	node->next = *p_head;
	*p_head = node;
	return (node);
}