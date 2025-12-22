/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:28:42 by kkwek             #+#    #+#             */
/*   Updated: 2025/12/04 17:28:44 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	pointer(void *ptr)
{
	unsigned long	cold;
	int				num;

	num = 2;
	cold = (unsigned long) ptr;
	if (cold == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (num + lower(cold));
}
