#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		lower(unsigned long num);
int		upper(unsigned long num);
int		percent(void);
int		pointer(void *ptr);
int		unsignedecimal(unsigned int n);

int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_putnbr(int n);
int		ft_putchar(int c);
int		ft_putstr(char *s);

int		handle_conversion(char specifier, va_list args);
int		ft_printf(const char *format, ...);

#endif
