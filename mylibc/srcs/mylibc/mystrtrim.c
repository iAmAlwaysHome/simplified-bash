 

#include "../../incs/mylibc.h"

char	*mystrtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = mystrlen(s1) - 1;
	while (mystrchr(set, s1[start]) && s1[start])
		start++;
	while (mystrchr(set, s1[end]) && end > 0)
		end--;
	str = mysubstr(s1, start, end - start + 1);
	if (!str)
		return (NULL);
	return (str);
}
