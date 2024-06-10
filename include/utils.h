#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "structures.h"

size_t	ft_strlen(const char *s);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char *s, char limiter);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *s);
int		ft_isdigit(int c);
bool	ft_iswhitespace(int c);

void	error(int error_code, t_all *data);

#endif