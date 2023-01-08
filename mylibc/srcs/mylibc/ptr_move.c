 //   By: Arthur Prahin 

#include "halloc.h"

void	*ptr_move(void *ptr, int dist)
{
	char	*cast;

	cast = (char *) ptr;
	return (cast + dist);
}
