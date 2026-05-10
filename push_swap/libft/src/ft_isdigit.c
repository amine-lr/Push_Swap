/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:24:28 by molariou          #+#    #+#             */
/*   Updated: 2026/04/27 22:15:47 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*int main()
{
	int bla = '2';
	int A = 'S';
	int B = '9';
	int f = 0;

	printf("%d.\n", ft_isdigit(bla));
	printf("%d.\n", ft_isdigit(A));
	printf("%d.\n", ft_isdigit(B));
	printf("%d.\n", ft_isdigit(f));
	return (0);
}*/
