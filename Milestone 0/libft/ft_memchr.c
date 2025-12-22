/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:07:11 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 19:07:15 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*loc;
	unsigned char		find;
	size_t				num;

	loc = s;
	find = (unsigned char) c;
	num = 0;
	while (n--)
	{
		if (loc[num] == find)
			return ((void *)&loc[num]);
		num++;
	}
	return (NULL);
}
