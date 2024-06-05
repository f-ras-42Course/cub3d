#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
void	ft_putendl_fd(char *s, int fd);

void	error(int error_code, t_data *all);

#endif