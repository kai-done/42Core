/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:08:51 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 19:08:54 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			test;
	unsigned char	*ptr;

	test = 0;
	ptr = (unsigned char *)s;
	while (test < n)
	{
		ptr[test] = 0;
		test++;
	}
}
