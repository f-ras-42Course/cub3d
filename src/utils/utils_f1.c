
#include "utils.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 10 && n >= 0)
	{
		ft_putchar_fd(n + '0', fd);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	if (n < 0)
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		else
		{
			ft_putchar_fd('-', fd);
			n *= -1;
			ft_putnbr_fd(n, fd);
		}
	}
}

bool	fr_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
