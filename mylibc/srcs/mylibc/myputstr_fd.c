 
#include "../../incs/mylibc.h"

void	myputstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	write(fd, s, mystrlen(s));
}
