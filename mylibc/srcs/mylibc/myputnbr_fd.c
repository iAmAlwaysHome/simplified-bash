 
#include "../../incs/mylibc.h"

void	myputnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		myputchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
		myputnbr_fd(n / 10, fd);
	digit = '0' + (n % 10);
	write(fd, &digit, 1);
}
