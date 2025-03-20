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

char	*ft_joinstr(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	free(s1);
	ft_strcat(result, s2);
	return (result);
}

char	*ft_read_line(t_list *p_head, t_list *node, int fd)
{
	ssize_t			bts_rd;
	char			tmp_buf[BUFFER_SIZE + 1];
	char			*newline;
	char			*curline;

	while (1)
	{
		bts_rd = read(fd, tmp_buf, BUFFER_SIZE);
		if (bts_rd == -1 || (node->str_buf == NULL && bts_rd == 0))
		{
			ft_delete_node(&p_head, fd);
			return (NULL);
		}
		tmp_buf[bts_rd] = '\0';
		node->str_buf = ft_joinstr(node->str_buf, tmp_buf);
		newline = ft_strchr(node->str_buf, '\n');



		if (newline)
		{
			curline = ft_substr(node->str_buf, 0, newline - node->str_buf + 1);
			char *rest = ft_strdup(newline + 1);
			free(node->str_buf);
			node->str_buf = rest;
			return (curline);
		}
		if (bts_rd == 0)
		{
			curline = node->str_buf;
			node->str_buf = NULL;
			ft_delete_node(&p_head, fd);
			return (curline);
		}
	}
}

char	*get_next_line(int fd)
{
	ssize_t			bts_rd;
	static t_list	*p_head;
	t_list			*node;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	node = get_or_create_node(&p_head, fd);
	if (node == NULL)
		return (NULL);
	bts_rd = read(fd, node->str_buf, 0);
	if (bts_rd == -1)
		return (NULL);
	next_line = ft_read_line(p_head, node, fd);
	return (next_line);
}
