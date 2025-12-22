/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remaining.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:29:13 by kkwek             #+#    #+#             */
/*   Updated: 2025/12/04 17:29:15 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	lower(unsigned long num)
{
	char	taken;
	int		count;

	count = 0;
	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (num >= 16)
		count = count + lower(num / 16);
	taken = "0123456789abcdef"[num % 16];
	ft_putchar(taken);
	return (count + 1);
}

int	upper(unsigned long num)
{
	char	wow;
	int		count;

	count = 0;
	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (num >= 16)
		count = count + upper(num / 16);
	wow = "0123456789ABCDEF"[num % 16];
	ft_putchar(wow);
	return (count + 1);
}

int	percent(void)
{
	write(1, "%", 1);
	return (1);
}
