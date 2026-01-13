#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

// Helper: joins s1 and s2, frees s1 to avoid leaks
static char *join_and_free(char *s1, char *s2)
{
    char *res = ft_strjoin(s1, s2);
    free(s1); // free old line
    return res;
}

char *get_next_line(int fd)
{
    static char *left;             // leftover from previous call
    char buffer[BUFFER_SIZE + 1];
    char *line;
    char *tmp;
    int bytes_read;
    int i;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    // allocate initial line buffer
    line = malloc(1);
    if (!line)
        return NULL;
    line[0] = '\0';

    // prepend leftover if it exists
    if (left)
    {
        line = join_and_free(line, left);
        free(left);
        left = NULL;
    }

    // read loop
    while (1)
    {
        // search for newline in current line
        i = 0; // reset i each loop
        while (line[i] && line[i] != '\n')
            i++;

        if (line[i] == '\n') // newline found
        {
            // save leftover after newline
            left = ft_strdup(&line[i + 1]);
            line[i + 1] = '\0';
            return line;
        }

        // read more from fd
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0) // EOF or error
            break;

        buffer[bytes_read] = '\0';
        line = join_and_free(line, buffer);
        if (!line)
            return NULL;
    }

    // if something is left in line at EOF, return it
    if (line[0] != '\0')
        return line;

    free(line);
    return NULL;
}

