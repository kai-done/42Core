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
	//printf("BUFFER: %p\n", buffer);
	if (remainder)
	{
//		printf("remainder is NOT NULL!");
		i = 0;
		while (remainder[i])
		{
			buffer[i] = remainder[i];
			i++;
		}
		buffer[i] = '\0';
		byte_read = i;
		//printf("buffer: \"%s\"", buffer);
		free(remainder);
		remainder = NULL;
	}
	else
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
	}

	if (byte_read < 0)
	{
		if (remainder)
		{
			free(remainder);
			remainder = NULL;
		}
		return (free(buffer), NULL);
	}
	line = NULL;

	while (byte_read > 0)
	{
		i = 0;
//		printf("Byte read: %d\n", byte_read);
		buffer[byte_read] = '\0';
		line = join(line, buffer);
		if (line == NULL)
			return (free(buffer), free(remainder), NULL);
		while (line[i] != '\0' && line[i] != '\n')
			i++;
		if (line[i] == '\n')
		{
			//printf("[i: %d]", i);
			if (line[i + 1] != '\0')
			{
				remainder = duplicate(&line[i + 1]);
				//printf("remainder: %s", remainder);
				if (remainder == NULL)
					return (free(buffer), free(line), NULL);
				line[i + 1] = '\0';
			}
			return (free(buffer), line);
		}
//		printf("Buffer: %p\n", buffer);
		byte_read = read(fd, buffer, BUFFER_SIZE);
	}
//	printf("Exit while\n");
	if (line && line[0] != '\0')
		return (free(buffer), line);
	return (free(line), free(buffer), NULL);
}
/*
#include <sys/stat.h>
#include <fcntl.h>
int main(void)
{
	char *line;
	//int fd = open("multiple_nlx5", O_RDONLY);
	int fd = open("41_with_nl", O_RDONLY);
	
	line = get_next_line(fd);
	while (line) {
		printf("-->|%s|", line);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	//if (line)
	//	free(line);
	close(fd);
}
*/
