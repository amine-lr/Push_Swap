/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:14:20 by molariou          #+#    #+#             */
/*   Updated: 2026/04/27 22:13:02 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	dst = malloc(len);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, len);
	return (dst);
}
/*
int main()
{
    char *s1 = NULL;
    char *copy;

    copy = ft_strdup(s1);

    printf("Original: %s\n", s1);
    if (!copy)
        printf("Failed to duplicate NULL string.\n");
    else
        printf("Copy:     %s\n", copy);
    free(copy);
    return (0);
}*/
