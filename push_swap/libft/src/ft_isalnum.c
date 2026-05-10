/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:23:53 by molariou          #+#    #+#             */
/*   Updated: 2026/04/27 22:14:51 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*int main()
{
	int AM = 0;
	int B = '-';
	int D = 'F';
	int S = 'd';

	printf("%d\n", ft_isalnum(AM));
	printf("%d\n", ft_isalnum(B));
	printf("%d\n", ft_isalnum(D));
	printf("%d\n", ft_isalnum(S));
}*/