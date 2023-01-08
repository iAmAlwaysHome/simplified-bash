 

#include "../../incs/mylibc.h"

//wrapers around myput functions that affect printf struct charsprinted
void	printf_putchar(t_count *print, char c, int fd)
{
	myputchar_fd(c, fd);
	print->chars_printed = print->chars_printed + 1;
}

void	printf_putstr(t_count *print, char *str, int fd)
{
	myputstr_fd(str, fd);
	print->chars_printed = print->chars_printed + mystrlen(str);
}

void	printf_putnbr(t_count *print, int n, int fd)
{
	char	*str;

	str = myitoa(n);
	printf_putstr(print, str, fd);
	free(str);
}
