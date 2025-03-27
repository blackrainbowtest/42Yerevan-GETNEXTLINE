/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:01:21 by aramarak          #+#    #+#             */
/*   Updated: 2025/03/23 14:01:23 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
* ft_strlen: returns the length of the string
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
* ft_strchr: returns a pointer to the first occ of the chr c in the string s
*/
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

/*
* ft_strjoin: concatenates two strings
*/
char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	char	*temp;

	len1 = (s1 != NULL) * ft_strlen(s1);
	len2 = (s2 != NULL) * ft_strlen(s2);
	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (NULL);
	temp = result;
	if (s1)
	{
		while (*s1)
			*temp++ = *s1++;
	}
	if (s2)
		while (*s2)
			*temp++ = *s2++;
	*temp = '\0';
	return (result);
}

/*
* ft_get_first_line: returns the first line of the string
*/
char	*ft_get_first_line(char *s)
{
	int		i;
	char	*str;

	if (!s || !s[0])
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		str[i] = s[i];
		i--;
	}
	return (str);
}

/*
* ft_remove_read_line: removes the first line of the string
*/
char	*ft_remove_read_line(char *s)
{
	char	*result;
	int		i;
	int		j;

	if (!s || !s[0])
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	result = malloc(ft_strlen(s) - i + 1);
	if (!result)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		result[j++] = s[i++];
	result[j] = '\0';
	free(s);
	return (result);
}
