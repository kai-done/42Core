/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:05:40 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 19:05:42 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	num;

	num = 0;
	if (size > 0)
	{
		while (src[num] != '\0' && num < size - 1)
		{
			dst[num] = src[num];
			num++;
		}
		dst[num] = '\0';
	}
	while (src[num] != '\0')
		num++;
	return (num);
}
