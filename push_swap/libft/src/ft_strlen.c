/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:15:48 by molariou          #+#    #+#             */
/*   Updated: 2026/04/27 21:57:49 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != ('\0'))
		i++;
	return (i);
}

/*int main()
{
    char *s =NULL;
	int rst = ft_strlen(s);
	printf ("the lenght of s is %d\n", rst);
	return (0);
}*/
