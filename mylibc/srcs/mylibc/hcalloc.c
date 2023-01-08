 //   By: Arthur Prahin 

#include "halloc.h"

void	*hcalloc(int count, int size)
{
	int		i;
	char	*data;

	data = hmalloc(count * size);
	i = -1;
	while (++i < count * size)
		*(data + i) = '\0';
	return (data);
}
