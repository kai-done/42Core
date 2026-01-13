#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		length(char *s1)
{
	int	i;
	
	i = 0;
	while (s1[i] != '\0')
		i++;
	return (i);
}

char	*join(char *s1, char *s2)
{
	char	*s3;
	int		lens1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	lens1 = length(s1);
	s3 = malloc(lens1 + length(s2) + 1);
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
	return (s3);
	
}

char	*join_and_free(char *s1, char *s2)
{
	char	*s3;
	
	s3 = join(s1, s2);
	free(s1);
	s1 = NULL;
	return (s3);
}

char	*duplicate(char *s1)
{
	int		i;
	char	*s2;
	
	i = 0;
	s2 = malloc(length(s1) + 1);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*buffer;
	int			i;
	int			byte_read;
	
	i = 0;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);	
	line = malloc (BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(line), NULL);
	byte_read = read(fd, buffer, BUFFER_SIZE);
	if (read > 0)
	
	line[0] = '\0';
	while (byte_read > 0)
	{
		buffer[byte_read] = '\0';
		if (remainder)
			line = join_and_free(line, remainder);
		line = join_and_free(line, buffer);
		while (line[i] != '\0' && line[i] != '\n')
			i++;
		if (line[i] == '\n')
		{
			if (line[i + 1] != '\0')
			{
				remainder = duplicate(&line[i + 1]);
				line[i + 1] = '\0';
			}
			return (line);
		}
		byte_read = read(fd, buffer, BUFFER_SIZE);
	}
	
	if (line != '\0' || byte_read != 0)
		return (line);
	return (free(line), free(buffer), NULL);
}
