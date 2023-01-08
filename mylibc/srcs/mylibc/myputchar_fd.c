 

#include "../../incs/mylibc.h"

void	myputchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}
