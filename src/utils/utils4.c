# include "cub3d.h"

bool	isinset(char n, char *set)
{
	while (*set && n != *set)
		set++;
	return (*set == n);
}

t_str	*strnew(char *s)
{
	t_str	*new;

	new = malloc(sizeof(t_str));
	if (!new)
		return (NULL);
	new->str = s;
	new->len = ft_strlen(s);
	new->next = NULL;
	return (new);
}

void	straddback(t_str **head, t_str *new)
{
	t_str	*tmp;

	tmp = *head;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	free_str(t_str *head)
{
	t_str	*to_free;

	while (head)
	{
		to_free = head;
		head = head->next;
		free(to_free->str);
		free(to_free);
	}
}

void	free_double_pointer(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
