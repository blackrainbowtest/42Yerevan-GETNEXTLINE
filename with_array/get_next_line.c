/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurgaspa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:39:01 by gurgaspa          #+#    #+#             */
/*   Updated: 2025/04/15 18:13:37 by gurgaspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_stroke(int fd, char *store)
{
	char	*buf;
	int		count;
	char	*new_store;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	count = 1;
	while ((!ft_strchr(store, '\n')) && (count > 0))
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1)
		{
			free(buf);
			free(store);
			return (NULL);
		}
		buf[count] = '\0';
		new_store = ft_strjoin(store, buf);
		free(store);
		store = new_store;
	}
	free(buf);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store[fd] = read_stroke(fd, store[fd]);
	if (!store[fd])
		return (NULL);
	line = ft_find_line(store[fd]);
	store[fd] = ft_save_line(store[fd]);
	return (line);
}
