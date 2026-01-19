#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	num;

	num = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[num])
	{
		write(1, &s[num], 1);
		num++;
	}
	return (num);
}
