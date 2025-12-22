/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:47:02 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 20:47:02 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	num;

	num = 0;
	if (s == NULL)
		return ;
	while (s[num])
	{
		write(fd, &s[num], 1);
		num++;
	}
}
