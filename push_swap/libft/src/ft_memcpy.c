/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:57:26 by molariou          #+#    #+#             */
/*   Updated: 2026/04/27 19:57:26 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_c;
	unsigned const char	*src_c;

	if (!dst &&!src)
		return (NULL);
	dst_c = (unsigned char *)dst;
	src_c = (unsigned const char *)src;
	i = 0;
	while (i < n)
	{
		dst_c[i] = src_c [i];
		i++;
	}
	return (dst);
}

/*#include <string.h>
int main()
{
	char    src[] = "hello";
	char    dst1[10] = {0};
	char    dst2[10] = {0};

	ft_memcpy(dst1, src, 3);
	memcpy(dst2, src, 3);
	
	printf("ft_memcpy: %s\n", dst1);
	printf("memcpy:    %s\n", dst2);
	printf("Match: %s\n", memcmp(dst1, dst2, 6) == 0 ? "YES ✓" : "NO ✗");
	
	return 0;
}*/
