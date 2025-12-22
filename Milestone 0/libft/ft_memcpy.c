/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:06:43 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 19:06:46 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*paste;
	const unsigned char	*copy;
	size_t				num;

	paste = dest;
	copy = src;
	num = 0;
	while (num < n)
	{
		paste[num] = copy[num];
		num++;
	}
	return (dest);
}
