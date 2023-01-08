 

#include "../../incs/mylibc.h"

char	*mystrrchr(const char *s, int c)
{
	char	*match;

	match = 0;
	while (*s)
	{
		if (*s == c)
			match = (char *)s;
		s++;
	}
	if (*s == c)
		match = (char *)s;
	return (match);
}
