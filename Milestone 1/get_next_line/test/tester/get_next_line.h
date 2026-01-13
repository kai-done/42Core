
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <fcntl.h>
# include <stdint.h>
# include <stddef.h>


int		strilen(const char *s1);
char	*stridup(const char *s1);
char	*strjoin(char *s1, char *s2);
char	*join_and_free(char *s1, char *s2);
char	*get_next_line(int fd);

#endif 
