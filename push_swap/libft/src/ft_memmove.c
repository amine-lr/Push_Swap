/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:12:08 by molariou          #+#    #+#             */
/*   Updated: 2026/04/25 13:12:08 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	s = (char *) src;
	d = (char *) dst;
	i = 0;
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

/*int main()
{
    char    *src = NULL;
    char	dst[20];

    ft_memmove(dst, src, 13);
	if (src)
    	printf("Source: %s\nDestination: %s\n", src, dst);
    else
		printf("src: %s", src);
    return (0);
}*/
