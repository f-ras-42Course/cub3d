#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
void	ft_putendl_fd(char *s, int fd);

void	error(char *error_message, int exit_code);

#endif