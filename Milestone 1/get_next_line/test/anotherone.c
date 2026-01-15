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

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*buffer;
	int			i;
	int			byte_read;
	
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);	
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte_read = read(fd, buffer, BUFFER_SIZE);

	line = NULL;
	while (byte_read > 0)
	{
		i = 0;
		buffer[byte_read] = '\0';
		if (remainder)
		{
			line = join_and_free(line, remainder);
			free(remainder);
			remainder = NULL;
		}
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
			return (free(buffer), line);
		}
		byte_read = read(fd, buffer, BUFFER_SIZE);
	}
	
	if (line != '\0' || byte_read != 0)
		return (free(buffer), line);
	return (free(line), free(buffer), NULL);
}
