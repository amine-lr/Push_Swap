/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:16:36 by molariou          #+#    #+#             */
/*   Updated: 2026/04/25 13:16:37 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	str2_len;

	if (!str2 || !*str2)
		return ((char *)str1);
	if (!str1)
		return (NULL);
	str2_len = ft_strlen(str2);
	while (*str1 != '\0' && len >= str2_len)
	{
		if (*str1 == *str2 && ft_strncmp(str1, str2, str2_len) == 0)
			return ((char *)str1);
		str1++;
		len--;
	}
	return (NULL);
}
/*int main()
{
    const char *sr1 = NULL;
    const char *sr2 = "NULL";
    size_t len = 9;
    char *result = ft_strnstr(sr1, sr2, len);
    
    if (result)
        printf("Found: %s\n", result);
    else
    {
        // Safe check: print "NULL" as a string if the pointer is NULL
        printf("'%s' not found in %s.\n", sr2, sr1 ? sr1 : "NULL");
    }
    return (0);
}*/