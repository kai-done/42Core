/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:05:14 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 19:05:16 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strncmp(const char *a, const char *b, size_t c)
{
	size_t	num;
	int		result;

	num = 0;
	result = 0;
	while ((a[num] != '\0' || b[num] != '\0') && num < c)
	{
		if (a[num] != b[num])
		{
			result = (unsigned char)a[num] - (unsigned char)b[num];
			break ;
		}
		num++;
	}
	if (num == c)
		return (0);
	result = (unsigned char)a[num] - (unsigned char)b[num];
	return (result);
}
