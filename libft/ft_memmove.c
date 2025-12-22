/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:06:32 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 19:06:35 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				num;

	d = dest;
	s = src;
	if (d > s && d < s + n)
	{
		num = n;
		while (num > 0)
		{
			d[num - 1] = s[num - 1];
			num--;
		}
	}
	else
	{
		num = 0;
		while (num < n)
		{
			d[num] = s[num];
			num++;
		}
	}
	return (dest);
}
