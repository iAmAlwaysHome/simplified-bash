 

#include "../../incs/mylibc.h"

int	myatoi(const char *nptr)
{
	int	nint;
	int	nold;
	int	sign;

	sign = 1;
	nint = 0;
	nold = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (myisdigit(*nptr))
	{
		if (nint == 214748364 && *nptr == '8' && sign == -1)
			return (-2147483648);
		nold = nint;
		nint = nint * 10 + (*nptr - '0');
		if ((nold < 0 && nint > 0) || (nold > 0 && nint < 0))
			return ((sign == 1) * -1);
		nptr++;
	}
	return (sign * nint);
}
