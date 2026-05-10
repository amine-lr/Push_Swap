/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:24:47 by molariou          #+#    #+#             */
/*   Updated: 2026/04/27 19:54:29 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(long n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int num)
{
	int		len;
	char	*str;
	long	nbr;

	nbr = num;
	len = count_size(nbr);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	len--;
	while (nbr > 0)
	{
		str[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
/*int main(void)
{
    int     n;
    char    *res;

    // Test 1: Minimum Int
    n = -2147483648;
    res = ft_itoa(n);
    printf("Test Min: %s\n", res);
    free(res);

    // Test 2: Zero
    n = 0;
    res = ft_itoa(n);
    printf("Test Zero: %s\n", res);
    free(res);

    // Test 3: Negative
    n = -5;
    res = ft_itoa(n);
    printf("Test Neg: %s\n", res);
    free(res);

    return (0);
}*/