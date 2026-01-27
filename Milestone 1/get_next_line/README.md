*This project has been created as part of the 42 curriculum by kkwek.*

**Description: char \*get_next_line(int fd)**

get_next_line is used to get the next line from the file given, and it'll return the current line from the file until it reaches the end of file (EOF) or '\n'. The first line can be printed out when the code is called with printf, and it'll continue on printing the next line when enter is pressed. If there is a '\n' halfway through the line, it'll return the first part of the line, save the second part, and combines the remainder with the next line, when get_next_line is called again.

**Instructions:**

1. Understanding read:
  I first had to understand what read is and what it returns. 
  
  read (int fd, void *buffer, size_t count);
  fd: file descriptor (what you're reading from)
  buffer: where to store the data
  count: max number of bytes to read

  it's return values:
  > 0: signifys the number of bytes read
    0: signifys EOF, and that there's nothing left to be read
   -1: error

  So read fills the buffer with the bytes that has been read.

2. Figuring out how read works and how getnextline should work
   I did a simple code that has me figure out read works, then i use a simple while loop to have getnextline working. The code reads and stores everything till it reaches the EOF, so it doesn't actually stops when a new line is in the file. It just returns the whole thing that's in the file, which is not what getnextline is.

3. Fixing the code and having it return when '\n' is read

   The code has if loops added in the while for it to be able to return the line when it reaches '\n'.
   But i still end up having it loop through the entire file instead when i set the loop to be, while (read(fd, &text, 1) > 0)
   Along with how i didn't consider the fact on what to happen if the lines that's been read in after the '\n', so i need to have a remainder variable to store it for it to be able to used the next time getnextline is called
   
5. Understanding what static is for a variable and how to implement it in the code

   Helper functions is added and used into the new written code.
   Used: ft_strlen, ft_memcpy, ft_strdup, ft_strjoin, join_and_free
   all the ft_*.c are from libft
   join_and_free uses ft_strjoin, and free s1

   Malloc line, used while(read(fd, buffer, BUFFER_SIZE))
   using a if loop for the remainder, if there is remainder, combine the remainder with the current line read using join_and_free
   next, using char *temp, to join_and_free line and buffer together, then duplicating temp into line, while freeing temp after
   with a while loop, it scans through the line and check for '\0' and '\n'
   with it, it'll be easier to check for a new line with the if loop for next line to be safed to the remainder
   then reads through the file again, in case it hasn't reached the EOF or '\n', it'll read again so it can read till it reaches either EOF or '\n'
   
6. Troubleshooting the codes and it's bugs

   changed the helper functions that are being used
   used: length, duplicate, join
   duplicate uses length
   join uses duplicate and length while freeing s1
   for join, it duplicates an empty string if s1 is null, and returns null if either s1 or s2 is  null

  bringing the if loop for the remainder out and before the while loop, using it to be the placed in the buffer if there is any remainder remaining, without affecting the malloced size of buffer, and uses the i copied over from buffer to remainder as the byte_read
  else, byte_read would be gotten using the read function

  if byte_read is 0, the remaining lines in the remainder would need to be freed and nulled
  and once checking that a new line has been found, it needs to ensure that there isn't anything else after the '\n'
  if there is something else after the '\n', it would be duplicated in to the remainder, and it's next line would be '\0', to ensure that when it is printed out, it doesn't print the things after the '\n'
  needing to free everything that's been malloced, while making sure that i don't end up freeing things that aren't supposed to be freed
  
**Resources:**

  - man page for read
