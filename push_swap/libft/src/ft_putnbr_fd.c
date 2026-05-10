/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 20:01:12 by molariou          #+#    #+#             */
/*   Updated: 2026/04/27 20:01:12 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

/*int	main(void)
{
	// Test 1: Standard positive
	write(1, "Test 42: ", 9);
	ft_putnbr_fd(42, 1);
	write(1, "\n", 1);

	// Test 2: Zero
	write(1, "Test 0:  ", 9);
	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);

	// Test 3: Negative
	write(1, "Test -123: ", 11);
	ft_putnbr_fd(-123, 1);
	write(1, "\n", 1);

	// Test 4: INT_MAX
	write(1, "Test Max: ", 10);
	ft_putnbr_fd(2147483647, 1);
	write(1, "\n", 1);

	// Test 5: INT_MIN (The Boss Fight)
	write(1, "Test Min: ", 10);
	ft_putnbr_fd(-2147483648, 1);
	write(1, "\n", 1);

	return (0);
}*/