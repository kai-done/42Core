/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:05:52 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 19:05:55 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	num;
	size_t	end;
	size_t	sta;

	num = 0;
	end = 0;
	sta = 0;
	while (dst[end] != '\0')
		end++;
	while (src[sta] != '\0')
		sta++;
	if (size <= end)
		return (size + sta);
	while (src[num] != '\0' && (end + num) < size - 1)
	{
		dst[end + num] = src[num];
		num++;
	}
	dst[end + num] = '\0';
	return (end + sta);
}
