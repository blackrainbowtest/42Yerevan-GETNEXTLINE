#include "get_next_line.h"

/*
* ft_strlen: returns the length of the string
*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s != NULL && s[len])
		len++;
	return (len);
}

/*
* ft_strchr: returns a pointer to the first occurrence of the character c in the string s
*/
char	*ft_strchr(const char *s, int c)
{
	if (s == NULL || c < 0 || c > 255)
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
	return (result);
}

/*
* ft_get_first_line: returns the first line of the string
*/
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
	{
		result[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*
* ft_remove_read_line: removes the first line of the string
*/
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
	if (s1[i] == '\0')
	{
		return (s1);
	}
	
	result = malloc(sizeof(char) * (ft_strlen(s1) - i + 1 + 1));
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