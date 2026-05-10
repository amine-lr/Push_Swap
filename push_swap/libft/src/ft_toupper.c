/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 20:17:56 by molariou          #+#    #+#             */
/*   Updated: 2026/04/27 20:17:57 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*int	main()
{
	char ch = 'r';

	if (!ch)
		printf("NULL");
	else
    	printf("Uppercase of %c is %c\n", ch, ft_toupper(ch));
    return (0);
}*/
