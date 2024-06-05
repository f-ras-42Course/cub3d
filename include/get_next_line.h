
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
int		str_len_of_line(char *s, int check);
char	*new_stash(char *stash, int line_length, int check);
char	*gnl_join(char *next_line, char *stash, int line_length);
char	*get_n_line(char *next_line, char **stash, int fd);
int		use_stash(char **stash, char **next_line);
void	re_assign(char **stash, char **next_line, int o);

#endif