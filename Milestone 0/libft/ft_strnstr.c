/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:05:02 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 19:05:05 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	num;
	size_t	hek;

	num = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	if (len == 0)
		return (NULL);
	while (haystack[num] != '\0' && len > num)
	{
		hek = 0;
		while (haystack[num + hek] == needle[hek] && needle[hek] != '\0'
			&& len > (num + hek))
			hek++;
		if (needle[hek] == '\0')
			return ((char *)(haystack + num));
		num++;
	}
	return (NULL);
}
