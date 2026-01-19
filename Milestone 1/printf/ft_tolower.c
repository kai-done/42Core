#include <stdio.h>
#include <unistd.h>
#include "printf.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
