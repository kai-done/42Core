#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_putchar(int c)
{
	char	ca;

	ca = (char) c;
	write(1, &ca, 1);
	return (1);
}
