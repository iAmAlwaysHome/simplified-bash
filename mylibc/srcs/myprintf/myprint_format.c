 

#include "../../incs/mylibc.h"

void	print_x(t_count *print, unsigned int nbr, int fd)
{
	int	add;

	add = 55;
	if (print->format_char == 'x')
		add += 32;
	if (nbr >= 16)
	{
		print_x(print, nbr / 16, fd);
		print_x(print, nbr % 16, fd);
	}
	else
	{
		if (nbr < 10)
			printf_putchar(print, nbr + '0', fd);
		else
			printf_putchar(print, nbr + add, fd);
	}
}

void	print_u(t_count *print, unsigned int nbr, int fd)
{
	if (nbr >= 10)
	{
		print_u(print, nbr / 10, fd);
		print_u(print, nbr % 10, fd);
	}
	else
		printf_putchar(print, nbr + '0', fd);
}

void	print_p(t_count *print, unsigned long nbr, int fd)
{
	if (nbr >= 16)
	{
		print_p(print, nbr / 16, fd);
		print_p(print, nbr % 16, fd);
	}
	else
	{
		if (nbr < 10)
			printf_putchar(print, nbr + '0', fd);
		else
			printf_putchar(print, nbr + 87, fd);
	}
}
