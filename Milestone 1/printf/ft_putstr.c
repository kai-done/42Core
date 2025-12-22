/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:47:02 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 20:47:02 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
