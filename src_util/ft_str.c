#include "includes.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char	*dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (len < size && dst[len] != '\0')
		len++;
	if (!src)
		return (len);
	while (len + i + 1 < size && src[i] != '\0')
	{
		dst[len + i] = src[i];
		i++;
	}
	if (len + i < size)
		dst[len + i] = '\0';
	while (src[i] != '\0')
		i++;
	return (len + i);
}

int	ft_strncmp(char *a, char *b, size_t n)
{
	size_t	i;

	i = 0;
	if (!a || !b)
		return (-1);
	while ((a[i] || b[i]) && i < n)
	{
		if (a[i] != b[i])
			return ((unsigned char)a[i] - (unsigned char)b[i]);
		i++;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	char	*current;

	current = (char *)s;
	if (!current)
		return (NULL);
	while (*current != (char)c)
	{
		if (*current == '\0')
			return (NULL);
		current++;
	}
	return (current);
}
