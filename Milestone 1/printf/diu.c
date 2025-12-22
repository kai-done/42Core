/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:28:56 by kkwek             #+#    #+#             */
/*   Updated: 2025/12/04 17:29:01 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	unsignedecimal(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count = count + unsignedecimal(n / 10);
	count = count + ft_putchar(n % 10 + '0');
	return (count);
}
