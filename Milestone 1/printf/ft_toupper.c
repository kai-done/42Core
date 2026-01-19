#include <stdio.h>
#include <unistd.h>
#include "printf.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
