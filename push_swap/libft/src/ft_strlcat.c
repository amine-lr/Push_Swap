/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 20:17:10 by molariou          #+#    #+#             */
/*   Updated: 2026/04/27 20:17:10 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	if (!src || (!dst && dstsize > 0))
		return (0);
	dest_size = 0;
	while (dst && dest_size < dstsize && dst[dest_size])
		dest_size++;
	src_size = ft_strlen(src);
	if (dstsize <= dest_size)
		return (src_size + dstsize);
	i = 0;
	while (src[i] && (dest_size + i + 1) < dstsize)
	{
		dst[dest_size + i] = src[i];
		i++;
	}
	dst[dest_size + i] = '\0';
	return (dest_size + src_size);
}

/*int main(void)
{
    char dst[50] = "AAMINEBLABLA   BALABA!";
    char *src = "AMINE";

    printf("Return: %zu\n", ft_strlcat(dst, src, sizeof(dst)));
    printf("Result: %s\n", dst);
    return (0);
}*/
