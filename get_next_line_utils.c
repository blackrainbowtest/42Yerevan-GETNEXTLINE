#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s != NULL && s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = 0;
	while (s != NULL && s[len])
		len++;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst != NULL && dst[i])
		i++;
	j = 0;
	while (src != NULL && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
