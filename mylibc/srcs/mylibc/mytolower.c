 

#include "../../incs/mylibc.h"

int	mytolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
