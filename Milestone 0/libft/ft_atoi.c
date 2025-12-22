/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:09:06 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 19:09:07 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_atoi(const char *c)
{
	int	num;
	int	sign;
	int	result;

	num = 0;
	sign = 1;
	result = 0;
	while ((c[num] >= 9 && c[num] <= 13) || c[num] == ' ')
		num++;
	if (c[num] == '-' || c[num] == '+')
	{
		if (c[num] == '-')
			sign = -1;
		num++;
	}
	while (c[num] >= '0' && c[num] <= '9')
	{
		result = result * 10 + (c[num] - '0');
		num++;
	}
	return (result * sign);
}
