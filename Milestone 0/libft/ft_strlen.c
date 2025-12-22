/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:05:29 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 19:05:31 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>

size_t	ft_strlen(const char *c)
{
	size_t	num;

	num = 0;
	while (c[num] != '\0')
		num++;
	return (num);
}
