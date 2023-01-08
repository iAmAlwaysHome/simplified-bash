 

#include "../../incs/mylibc.h"

void	mybzero(void *s, size_t n)
{
	mymemset(s, '\0', n);
}
