
#include "utils.h"
#include <limits.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while ((dstsize - 1) > i && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char *)malloc(ft_strlen(s1) + 1 * sizeof(char));
	if (str == 0)
		return (0);
	ft_strlcpy(str, s1, (ft_strlen(s1) + 1) * sizeof(char));
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	str_len_s;

	str_len_s = ft_strlen(s);
	if (start >= str_len_s)
		return (ft_strdup(""));
	if ((str_len_s - start) < len)
		len = str_len_s - start;
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_iswhitespace(*s))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result += 10 * (*s - '0');
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		return (0);
	return (result);
}
