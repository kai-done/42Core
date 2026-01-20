*This project has been created as part of the 42 curriculum by kkwek.*

Description: char *get_next_line(int fd)

get_next_line is used to get the next line from the file given, and it'll return the current line from the file until it reaches the end of file (EOF) or '\n'. The first line can be printed out when the code is called with printf, and it'll continue on printing the next line when enter is pressed. If there is a '\n' halfway through the line, it'll return the first part of the line, save the second part, and combines the remainder with the next line, when get_next_line is called again.
