/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:04:47 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 19:04:51 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	e;
	char	*o;
	int		a;

	e = (char) c;
	o = NULL;
	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] == e)
			o = ((char *)&s[a]);
		a++;
	}
	if (e == '\0')
		return ((char *)&s[a]);
	return (o);
}

// o = ((char *)&s[a]); // to make it not a const
