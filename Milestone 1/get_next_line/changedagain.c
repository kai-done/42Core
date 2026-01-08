/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_net_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:31:27 by kkwek             #+#    #+#             */
/*   Updated: 2025/12/11 16:31:36 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{

	static char *left;
	char		*line;
	char		*tmp;
	char		buffer[BUFFER_SIZE + 1];
	int			i;
	int			inner;
	
	if(BUFFER_SIZE <= 0 || fd == -1)
		return (NULL);
	line = malloc(BUFFER_SIZE + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	inner = read(fd, buffer, BUFFER_SIZE);
	
	line[0] = '\0';
	while (inner > 0)
	{
		buffer[inner] = '\0';
		if (left)
		{
			line = join_and_free(line, left);
			free(left);
			left = NULL;
		}
		tmp = join_and_free(line, buffer);
		if (tmp == NULL)
		{
			free(line);
			return (NULL);
		}
		line = ft_strdup(tmp);
		free(tmp);
		if (!line)
			return (NULL);
		i = 0;
		while(line[i] != '\0' && line[i] != '\n')
			i++;
		if (line[i] == '\n')
		{
			if (line[i + 1] != '\0')
				left = ft_strdup(&line[i + 1]);
			else
				left = NULL;
			line[i + 1] = '\0';
			return (line);
		}
		inner = read(fd, buffer, BUFFER_SIZE);
		buffer[inner] = '\0';
	}	
	
	if (inner == 0 && line && line[0] != '\0')
		return (line);
	free(line);
	return (NULL);
}


size_t	ft_strlen(const char *c)
{
	size_t	num;

	num = 0;
	while (c[num] != '\0')
		num++;
	return (num);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*paste;
	const unsigned char	*copy;
	size_t				num;

	paste = dest;
	copy = src;
	num = 0;
	while (num < n)
	{
		paste[num] = copy[num];
		num++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) + 1;
	copy = malloc(len);
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, s, len);
	return (copy);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;
	size_t	num;
	size_t	str1;

	num = 0;
	str1= ft_strlen(s1);
	len = str1 + ft_strlen(s2);
	s3 = (char *)malloc(len + 1);
	if (s3 == NULL)
		return (NULL);
	while (s1[num] != '\0')
	{
		s3[num] = s1[num];
		num++;
	}
	num = 0;
	while (s2[num] != '\0')
	{
		s3[num + str1] = s2[num];
		num++;
	}
	s3[len] = '\0';
	return (s3);
}

char	*join_and_free(char *s1, char *s2)
{
	char	*result;
	
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}
