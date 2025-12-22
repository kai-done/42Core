/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:47:13 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 20:47:14 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	num;

	num = 0;
	if (s == NULL)
		return ;
	while (s[num] != '\0')
	{
		write(fd, &s[num], 1);
		num++;
	}
	write(fd, "\n", 1);
}
