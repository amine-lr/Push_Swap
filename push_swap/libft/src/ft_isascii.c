/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:24:14 by molariou          #+#    #+#             */
/*   Updated: 2026/04/25 14:24:15 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*int	main()
{
	int	test1 = 'A';
	int	test2 = 'c';
	int	test3 = '@';
	int	test4 = '5';
	int	test5 = 0;

	printf("%d.\n", ft_isascii(test1));
	printf("%d.\n", ft_isascii(test2));
	printf("%d.\n", ft_isascii(test3));
	printf("%d.\n", ft_isascii(test4));
	printf("%d.\n", ft_isascii(test5));
	return (0);
}*/
