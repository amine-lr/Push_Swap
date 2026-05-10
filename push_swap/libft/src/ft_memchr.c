/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:10:40 by molariou          #+#    #+#             */
/*   Updated: 2026/04/25 13:10:40 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_c;

	i = 0;
	if (!s)
		return (NULL);
	s_c = (unsigned char *)s;
	while (i < n)
	{
		if (s_c[i] == (unsigned char)c)
			return (s_c + i);
		i++;
	}
	return (NULL);
}

/*t main(void)
{
    char    *str = "Find the needle";
    char    *rst;

    rst = (char *)ft_memchr(str, 'n', 15);
    if (rst)
        printf("Found 'n' at index: %ld\n", rst - str);

    rst = (char *)ft_memchr(str, 'e', 5);
    if (!rst)
        printf(" not found within first 5 bytes\n");

    char data[] = {1, 2, 0, 4, 5};
    rst = ft_memchr(data, 0, 5);
    if (rst)
        printf("Found the 0 byte at index: %ld\n", rst - data);

    return (0);
}*/
