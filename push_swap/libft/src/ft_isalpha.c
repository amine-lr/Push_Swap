/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:24:01 by molariou          #+#    #+#             */
/*   Updated: 2026/04/27 22:13:17 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z' ) || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/*int	main()
{
	char	A = 0;
	char	B = 'g';
	char	c = '5';
	char	d = '-';

	printf("%d.\n", ft_isalpha(A));
	printf("%d.\n", ft_isalpha(B));
	printf("%d.\n", ft_isalpha(c));
	printf("%d.\n", ft_isalpha(d));
	return (0);
}*/
