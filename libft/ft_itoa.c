/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:46:00 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 20:46:01 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	get_len(long tmp)
{
	int	len;

	len = 0;
	if (tmp <= 0)
		len++;
	while (tmp != 0)
	{
		tmp = tmp / 10;
		len++;
	}
	return (len);
}

static void	fill_str(char *str, long nb, int len)
{
	int	i;

	i = len - 1;
	if (nb == 0)
	{
		str[0] = '0';
		return ;
	}
	if (nb < 0)
		nb = -nb;
	while (nb != 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = get_len(nb);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	fill_str(str, nb, len);
	return (str);
}

/*
char	*ft_itoa(int n)
{
	char	*str;
	int	len;
	int	i;
	long	nb;
	long	tmp;

	len = 0;
	nb = n;

	if (nb < 0)
	{
		nb = -nb;
		len++;
	}

	tmp = nb;

	if (nb == 0)
		len = 1;

	while (tmp != 0)
	{
		tmp = tmp / 10;
		len++;
	}
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);

	str[len] = '\0';
	i = len - 1;

	if (nb == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';

	while (nb != 0)
	{
		str[i] = (nb%10) + '0';
		nb = nb/10;
		i--;
	}
	return str;
}


char	*ft_itoa(int n)
{
	char	*str;
	int	len = 1;
	int	neg = 0;
	
	if (n < 0)
	{
		if (n == -2147483648)
			return ("-2147483648");
		n = -n;
		len++;
	}
	if ((n/10) == 0)
	{
		str = str * 10 + (n + '0');
	}
	while ((n%10) != 0)
	{
		ft_itoa(n/10);
	}
	return (n);
}


char *ft_itoa(int n)
{
    char *str;
    long nb = n;       // use long to handle INT_MIN safely
    int len = 0;       // length of the string
    long tmp = nb;

    // Handle negative numbers
    if (n <= 0)
        len = 1;      // reserve space for '-' or '0'

    if (nb < 0)
        nb = -nb;

    // Count digits
    while (tmp != 0)
    {
        tmp /= 10;
        len++;
    }

    str = (char *)malloc(len + 1);
    if (!str)
        return NULL;
    str[len] = '\0';

    // Handle zero
    if (n == 0)
    {
        str[0] = '0';
        return str;
    }

    // Handle negative
    if (n < 0)
        str[0] = '-';

    // Fill string from the end
    while (nb != 0)
    {
        str[--len] = (nb % 10) + '0';
        nb /= 10;
    }

    return str;
}


char *ft_itoa(int n)
{
    char *str;
    size_t len = 1;  // At least 1 digit (for 0)

    // Handle negative numbers
    int is_negative = 0;
    if (n < 0)
    {
        if (n == -2147483648)  // Special case for INT_MIN
        {
            return "-2147483648";  // Directly return the string for INT_MIN
        }
        is_negative = 1;
        n = -n;  // Work with positive version
        len++;   // Account for the minus sign
    }

    // Calculate the length of the number
    int tmp = n;
    while (tmp >= 10)
    {
        len++;
        tmp /= 10;
    }

    str = (char *)malloc(len + 1);  // +1 for the null-terminator
    if (!str)
        return NULL;  // Return NULL if memory allocation fails

    str[len] = '\0';  // Null-terminate the string

    // Fill the string with digits (from the end to the beginning)
    while (n >= 10)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    str[--len] = (n % 10) + '0';  // The last digit

    if (is_negative)
        str[0] = '-';  // Add the negative sign if needed

    return str;
}


#include <stdlib.h>  // For malloc()

// Helper function to handle the negative case and INT_MIN
static int ft_handle_special_case(int *n, size_t *len)
{
    if (*n == -2147483648)  // Special case for INT_MIN
        return 1;  // Return 1 to indicate INT_MIN special case

    if (*n < 0) {  // Handle negative numbers
        *n = -(*n);  // Convert to positive
        *len += 1;   // Account for the negative sign
    }

    return 0;  // Return 0 for normal cases
}

char *ft_itoa(int n)
{
    char *str;
    size_t len = 1;  // At least 1 digit (for 0)

    // Handle special case for INT_MIN and negative numbers
    if (ft_handle_special_case(&n, &len)) {
        return "-2147483648";  // Special case for INT_MIN
    }

    // Calculate the length of the number (number of digits)
    int tmp = n;
    while (tmp >= 10) {
        len++;
        tmp /= 10;
    }

    // Allocate memory for the string
    str = (char *)malloc(len + 1);  // +1 for the null-terminator
    if (!str)
        return NULL;  // Return NULL if memory allocation fails

    str[len] = '\0';  // Null-terminate the string

    // Fill the string with digits (from the end to the beginning)
    while (n >= 10) {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    str[--len] = (n % 10) + '0';  // Last digit

    // Add the negative sign if necessary
    if (len > 0)
        str[0] = '-';  // Add negative sign if needed

    return str;
}

#include <stdlib.h>

static int	num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;                 // convert to long to handle INT_MIN safely
	len = num_len(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

*/
