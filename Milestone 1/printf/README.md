# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.md                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 20:57:03 by kkwek             #+#    #+#              #
#    Updated: 2025/12/08 20:57:06 by kkwek            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

*This project has been created as part of the 42 curriculum by kkwek.*

Description: 

Printf is a function in <stdio.h> and is used to print things out. The goal is to recreate the basic function of printf with this project. It involves using va_list to make the code work out. va_list variable is used to hold arguments, and is used to take in more arguments, suitable for printf.

It basically is to just recreate the simple functions of printf, like printing a string, integer, digit, percentage, etc.

Instructions: 

I started off with recreating the functions first. I split the functions up into 3s, so i could deal with them part by part, without needing to look at the whole thing from the start, then i did putchar, which is to write out the results given.

So i did the simple functions which were %c, %s, %d, %i and %%. They were to just print out simple things which have been done before with the write funtion. Then the next thing I did was %u. It's similar to %d, but the difference for it is that it is unsigned, so it wouldn't have a negative number. With that, i just had it looped through and use putchar to write out the results. Afterwards, I did %x & %X next. Since they're basically almost the same things, just one in capital letters, and one in small letters. Both flows around the same logic as %d & %i, the only difference is that %d & %i are base 10, while %x & %X are base 16. So with that logic, we just need to modify the code used for %d & %i, and use it for %X and %x. Using a lookup table, it can be used to ensure that the results that is being stored and printed for %x and %X, would correspond to the hexadecimal. Then once this is done, I'm only left with %p. Which is for the pointer. I used an unsigned long to get the address of the pointer. Then, using %x, i use it to print out the pointer argument out in hexadecimal. If no address is found, it would print nil instead of null, due to the library that has been used.

After all this is done, i realised something else after evaluting someone's printf. It was the fact that the code should also return out the number of characters being printed out, when asked to. So if printf is used while being declared in another variable, it should print out the number of characters that was printed out when printf was called earlier. So I had to revise my code to have it return the count of the characters being printed out when each function was called, without it actually printing out in the write function. It should only be printed out when printf is used with a variable and declared there. Then it gets printed out.

Resources: listing classic references related to the topic (documen-
tation, articles, tutorials, etc.), as well as a description of how AI was used —
specifying for which tasks and which parts of the projectoh
