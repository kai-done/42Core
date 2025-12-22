/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:06:55 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 19:06:57 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				num;
	const unsigned char	*ah;
	const unsigned char	*a;

	num = 0;
	ah = s1;
	a = s2;
	while (num < n)
	{
		if (ah[num] != a[num])
			return (ah[num] - a[num]);
		num++;
	}
	return (0);
}
