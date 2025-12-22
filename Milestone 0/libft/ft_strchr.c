/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:06:06 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 19:06:08 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		num;
	char	e;

	num = 0;
	e = (char) c;
	while (s[num] != '\0')
	{
		if (s[num] == e)
			return ((char *)&s[num]);
		num++;
	}
	if (e == '\0')
		return ((char *)&s[num]);
	return (NULL);
}
