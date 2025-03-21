#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s != NULL && s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s)
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	char	*temp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	temp = result;
	while (*s1 != '\0')
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	while (*s2 != '\0')
    {
        *temp = *s2;
        temp++;
        s2++;
    }
	*temp = '\0';
	free(s1);
	return (result);
}

char	*ft_get_first_line(char *s1)
{
	char	*result;
	int		i;

	if (s1 == NULL)
		return (NULL);
	if (s1[0] == '\0')
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	result = malloc(sizeof(char) * (i + 2));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
		result[i] = s1[i++];
	if (s1[i] == '\n')
		result[i] = s1[i++];
	result[i] = '\0';
	return (result);
}

char	*ft_remove_read_line(char *s1)
{
	char	*result;
	int		i;
	int		j;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!s1[i])
	{
		free(s1);
		return (NULL);
	}
	result = malloc(sizeof(char) * (ft_strlen(s1) - i + 1));
	if (!result)
		return (NULL);
	i++;
	j = 0;
	while (s1[i])
		result[j++] = s1[i++];
	result[j] = '\0';
	free(s1);
	return (result);
}