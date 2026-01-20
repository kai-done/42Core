#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int		length(char *s1)
{
	int	i;
	
	i = 0;
	if (s1 == NULL)
		return (0);
	while (s1[i] != '\0')
		i++;
	return (i);
}

char	*duplicate(char *s1)
{
	int		i;
	char	*s2;
	
	i = 0;
	if (s1 == NULL)
		return (NULL);
	s2 = malloc(length(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*join(char *s1, char *s2)
{
	char	*s3;
	int		lens1;
	int		i;
	int		j;

	i = 0;
	j = 0;

	if (s1 == NULL)
		s1 = duplicate("");
	if (s1 == NULL || s2 == NULL)
		return (free(s1), NULL);
	lens1 = length(s1);
	s3 = malloc(lens1 + length(s2) + 1);
	if (s3 == NULL)
		return (free(s1), NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	free(s1);
	return (s3);
	
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*buffer;
	int			i;
	int			byte_read;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);	
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte_read = read(fd, buffer, BUFFER_SIZE);

	if (byte_read < 0)
		return (free(buffer), NULL);
	line = NULL;

	if (remainder)
	{
		line = remainder;
		remainder = NULL;
	}

	while (byte_read > 0)
	{
		i = 0;
		buffer[byte_read] = '\0';
		line = join(line, buffer);
		if (line == NULL)
			return (free(buffer), free(remainder), NULL);
		while (line[i] != '\0' && line[i] != '\n')
			i++;
		if (line[i] == '\n')
		{
			if (line[i + 1] != '\0')
			{
				remainder = duplicate(&line[i + 1]);
				if (remainder == NULL)
					return (free(buffer), free(line), NULL);
				line[i + 1] = '\0';
			}
			return (free(buffer), line);
		}
		byte_read = read(fd, buffer, BUFFER_SIZE);
	}
	
	if (line && line[0] != '\0')
		return (free(buffer), line);
	if (remainder)
	{
		free(remainder);
		remainder = NULL;
	}
	return (free(line), free(buffer), NULL);
}
