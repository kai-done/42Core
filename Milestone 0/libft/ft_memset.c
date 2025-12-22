/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:06:21 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 19:06:23 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*um;
	unsigned char	a;
	size_t			num;

	um = s;
	a = (unsigned char) c;
	num = 0;
	while (num < n)
	{
		um[num] = a;
		num++;
	}
	return (s);
}
