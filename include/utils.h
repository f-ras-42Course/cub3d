#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
void	ft_putendl_fd(char *s, int fd);

int		error(char *error_message, int exit_code);

#endif