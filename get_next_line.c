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

char	*ft_read_line(t_list *node)
{

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

	printf("fd: %d\n", fd);
	return (NULL);
}
