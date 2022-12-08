#ifndef UTILS_H
# define UTILS_H
# include "includes.h"

int	ft_split(char ***split, char *s, char c);
int	ft_bzero(void *dst, size_t size);
int	ft_memcpy(void *dst, void *src, size_t len);
int	ft_memset(void *dst, int c, size_t n);
int	ft_itoa(char **res, int n);
int	ft_strdup(char **dst, char *src);

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);

#endif
