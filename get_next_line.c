/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:01:12 by aramarak          #+#    #+#             */
/*   Updated: 2025/03/23 14:01:14 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (curr->str_buf)
			{
				free(curr->str_buf);
				curr->str_buf = NULL;
			}
			free(curr);
			return ;
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

char	*ft_read_line(t_list **head, t_list *node, ssize_t bytes_read, int fd)
{
	char	*buffer;

	if (bytes_read <= 0 && (!node->str_buf || node->str_buf[0] == '\0'))
	{
		free(node->str_buf);
		node->str_buf = NULL;
		ft_delete_node(head, fd);
		return (NULL);
	}
	if (bytes_read == 0 && node->str_buf)
	{
		buffer = ft_get_first_line(node->str_buf);
		free(node->str_buf);
		node->str_buf = NULL;
		return (buffer);
	}
	if (!node->str_buf || node->str_buf[0] == '\0')
		return (NULL);
	buffer = ft_get_first_line(node->str_buf);
	node->str_buf = ft_remove_read_line(node->str_buf);
	return (buffer);
}

ssize_t	read_and_append_data(int fd, t_list *node, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	if (fd < 0 || !node || !buffer)
		return (-1);
	while (!ft_strchr(node->str_buf, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = node->str_buf;
		node->str_buf = ft_strjoin(node->str_buf, buffer);
		free(temp);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
	char			*buffer;
	ssize_t			bytes_read;

	node = get_or_create_node(&head, fd);
	if (!node)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = read_and_append_data(fd, node, buffer);
	free(buffer);
	return (ft_read_line(&head, node, bytes_read, fd));
}
