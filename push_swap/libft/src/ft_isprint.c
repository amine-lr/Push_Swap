/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:24:36 by molariou          #+#    #+#             */
/*   Updated: 2026/04/25 14:24:37 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*int	main()
{
	int	space = ' ';
	int	notprint = 0;

	printf("%d.\n", ft_isprint(space));
	printf("%d.\n", ft_isprint(notprint));
	return (0);
}*/
