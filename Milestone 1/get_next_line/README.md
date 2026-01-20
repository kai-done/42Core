*This project has been created as part of the 42 curriculum by kkwek.*

Description: char *get_next_line(int fd)

get_next_line is used to get the next line from the file given, and it'll return the current line from the file until it reaches the end of file (EOF) or '\n'. The first line can be printed out when the code is called with printf, and it'll continue on printing the next line when enter is pressed. If there is a '\n' halfway through the line, it'll return the first part of the line, save the second part, and combines the remainder with the next line, when get_next_line is called again.

Instructions:

1. Understanding read:
  I first had to understand what read is and what it returns. 
  
  read (int fd, void *buffer, size_t count);
  fd: file descriptor (what you're reading from)
  buffer: where to store the data
  count: max number of bytes to read

  it's return values:
  >0: signifys the number of bytes read
  0: signifys EOF, and that there's nothing left to be read
  -1: error

  So read fills the buffer with the bytes that has been read.

2. Figuring out how read works and how getnextline should work
   I did a simple code that has me figure out read works, then i use a simple loop to have getnextline working. The code reads and stores everything till it reaches the EOF,    so it doesn't actually stops when a new line is in the file. It just returns the whole thing that's in the file, which is not what getnextline is.

3. Fixing the code and having it return when '\n' is read
