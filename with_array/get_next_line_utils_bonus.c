/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurgaspa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:46:01 by gurgaspa          #+#    #+#             */
/*   Updated: 2025/04/15 17:56:25 by gurgaspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s, char *d)
{
	size_t	index;
	size_t	s_len;
	size_t	d_len;
	char	*result;

	s_len = (s != NULL) * ft_strlen(s);
	d_len = (d != NULL) * ft_strlen(d);
	result = (char *)malloc(s_len + d_len + 1);
	index = 0;
	if (!result)
		return (NULL);
	while (s && *s)
		result[index++] = *s++;
	while (d && *d)
		result[index++] = *d++;
	result[index] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (((unsigned char)*s) == c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((unsigned char)*s == c)
		return ((char *)s);
	return (NULL);
}

char	*ft_find_line(char *ptr)
{
	int		i;
	int		j;
	char	*cube;

	i = 0;
	j = 0;
	cube = 0;
	if (!ptr || (ptr[0] == '\0'))
		return (NULL);
	while (ptr[i] && (ptr[i] != '\n'))
		i++;
	if (ptr[i] == '\n')
		i++;
	cube = malloc(i + 1);
	if (!cube)
		return (NULL);
	while (j < i)
	{
		cube[j] = ptr[j];
		j++;
	}
	cube[j] = '\0';
	return (cube);
}

char	*ft_save_line(char *set)
{
	char	*caze;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!set)
		return (NULL);
	while (set[i] && (set[i] != '\n'))
		i++;
	if (!set[i])
	{
		free(set);
		return (NULL);
	}
	i += (set[i] == '\n');
	caze = malloc(ft_strlen(set) - i + 1);
	if (!caze)
		return (NULL);
	while (set[i])
		caze[j++] = set[i++];
	caze[j] = '\0';
	free(set);
	return (caze);
}
