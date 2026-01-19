*This project has been created as part of the 42 curriculum by kkwek.*

Description: 

Printf is a function in <stdio.h> and is used to print things out. The goal is to recreate the basic function of printf with this project. It involves using va_list to make the code work out. va_list variable is used to hold arguments, and is used to take in more arguments, suitable for printf.

It basically is to just recreate the simple functions of printf, like printing a string, integer, digit, percentage, etc.

Instructions: 

I started off with recreating the functions first. I split the functions up into 3s, so i could deal with them part by part, without needing to look at the whole thing from the start, then i did putchar, which is to write out the results given.

So i did the simple functions which were %c, %s, %d, %i and %%. They were to just print out simple things which have been done before with the write funtion. Then the next thing I did was %u. It's similar to %d, but the difference for it is that it is unsigned, so it wouldn't have a negative number. With that, i just had it looped through and use putchar to write out the results. Afterwards, I did %x & %X next. Since they're basically almost the same things, just one in capital letters, and one in small letters. Both flows around the same logic as %d & %i, the only difference is that %d & %i are base 10, while %x & %X are base 16. So with that logic, we just need to modify the code used for %d & %i, and use it for %X and %x. Using a lookup table, it can be used to ensure that the results that is being stored and printed for %x and %X, would correspond to the hexadecimal. Then once this is done, I'm only left with %p. Which is for the pointer. I used an unsigned long to get the address of the pointer. Then, using %x, i use it to print out the pointer argument out in hexadecimal. If no address is found, it would print nil instead of null, due to the library that has been used.

After all this is done, i realised something else after evaluting someone's printf. It was the fact that the code should also return out the number of characters being printed out, when asked to. So if printf is used while being declared in another variable, it should print out the number of characters that was printed out when printf was called earlier. So I had to revise my code to have it return the count of the characters being printed out when each function was called, without it actually printing out in the write function. It should only be printed out when printf is used with a variable and declared there. Then it gets printed out.

Afterwards, i added the codes all together, where i first worked on the main while learning about va_list. Then i worked out how the code works and get collected and called in the va_list and va_start. Then i used va_list for the arguments and used va_start to call the arguments and the formatting. Using the specifier, i call va_arg for each of the different type of arguments used, along with the type of variable is used and called in the spcific helper functions. It sorts through the code by looking for % sign first, then look for the following character after. With the character that is found, it would go through the spcifier list and find the character which is defined. Once it does, it'll go through the helper function and write out the code that is given, while returning the number of characters that's been written out. If not, it'll write out the things that's been given. It'll keep going until the end of the code. Then it'll end of with va_end, since it'll close the va_list code, since it's been started of with va_start.

1. Start of with learning about va_list:
   va_list, va_start, va_arg, va_end
   va_list is used for printf and it's arguments.

   va_list: holds the variable arguments
   va_start: initialize the arguement list
   va_arg: fetches the next argument
   va_end: cleans up

     * to use it, it is important to know the type of each argument read,
       arguments smaller than int(char, short) is promoted to int,
       unaware of knowing how many arguments exist, unless the info is passed explicitly,
       using the wrong type with va_arg causes undefined behaviour

2. Use of helper functions:
   %d, %i, %c, %s, %%, %x, %X, %u, %p

   %%; percentage
   it just write out the % sign when %% is used

   %s: string
   it writes out the string of the given input when called, used putstr for the code

   %d & %i: digit and integer
   it writes out the numbers given, and both uses putnbr to have the output written out, since it's in base 10

   %c: character
   it writes out the character using putchar

   %u: unsigned decimal
   it writes out the same as %i & %d, except that since it's unsigned, it's always positive, so it doesn't need to have the negative checker

   %x & %X: base 16 lower and upper case
   it writes out the number it receives and change it into base 16 and writes out what is given

   %p: pointer
   it writes out the address of the memory stored in the pointer, and using %x to write out the address

3. Combining it and making the main

   int ft_printf(const char *format, ...)

   ... is for the undefined amount of arguments that can be called and written out
   const char* format: the format parameteer is a format string, it tells the functions what to print and how to interpret the additional arguments (...)
   format is essentially what is written in the " " when printf is called

   using a branched out helper function for the main for va_args for each of the different characters given with the % sign
   the helper function of the main helps to call out to the other helper functions written that correlates to what is called

Resources: listing classic references related to the topic (documen-
tation, articles, tutorials, etc.), as well as a description of how AI was used —
specifying for which tasks and which parts of the projectoh

   - man page
