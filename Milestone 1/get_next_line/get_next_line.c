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

int	before(char **remainder, char *buffer, int byte_read, int fd)
{
	int	i;

	i = 0;
	if (*remainder)
	{
		while ((*remainder)[i])
		{
			buffer[i] = (*remainder)[i];
			i++;
		}
		buffer[i] = '\0';
		byte_read = i;
		free(*remainder);
		*remainder = NULL;
	}
	else
		byte_read = read(fd, buffer, BUFFER_SIZE);
	return (byte_read);
}

char	*during(int byte_read, char *line, char **remainder, char *buffer)
{
	int	i;

	i = 0;
	buffer[byte_read] = '\0';
	line = join(line, buffer);
	if (line == NULL)
		return (free(buffer), free(*remainder), NULL);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n' && line[i + 1] != '\0')
	{
		*remainder = duplicate(&line[i + 1]);
		if (*remainder == NULL)
			return (free(buffer), free(line), NULL);
		line[i + 1] = '\0';
	}
	return (line);
}


void	cleanup(int byte_read, char **remainder, char *line, char *buffer)
{
	if (byte_read < 0)
	{
		if (*remainder)
		{
			free(*remainder);
			*remainder = NULL;
		}
		free(buffer);
	}
	else 
	{
		free(line);
		free(buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*buffer;
	int			byte_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte_read = before(&remainder, buffer, 0, fd);
	line = NULL;
	while (byte_read > 0)
	{
		line = during(byte_read, line, &remainder, buffer);
		if (line == NULL)
			return (NULL);
		if (line[length(line) - 1] == '\n')
			return (free(buffer), line);
		byte_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (line && line[0] != '\0')
		return (free(buffer), line);
	return (cleanup(byte_read, &remainder, line, buffer), NULL);
}
