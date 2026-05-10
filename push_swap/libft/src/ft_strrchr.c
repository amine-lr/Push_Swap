/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 20:17:29 by molariou          #+#    #+#             */
/*   Updated: 2026/04/27 21:57:49 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char) c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char *str = NULL;

	// Test 1: Find 'i' (should find the second 'i')
	printf("Last 'i': %s\n", ft_strrchr(str, 'i'));

	// Test 2: Find 't' (the start)
	printf("Start 't': %s\n", ft_strrchr(str, 't'));

	// Test 3: Find '\0' (the end)
	if (ft_strrchr(str, '\0') == (str + 10))
		printf("Null terminator found! ✓\n");

	// Test 4: Not found
	printf("Not found 'z': %p\n", ft_strrchr(str, 'z'));

	return (0);
}*/
