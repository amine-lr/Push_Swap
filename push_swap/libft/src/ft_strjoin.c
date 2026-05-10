/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:15:01 by molariou          #+#    #+#             */
/*   Updated: 2026/04/27 21:57:48 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	tot_len;
	size_t	len_s1;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	tot_len = len_s1 + ft_strlen(s2);
	str = (char *)malloc(tot_len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str, s2, tot_len + 1);
	return (str);
}
/*
int main()
{
    char *s1 = NULL;
    char *s2 = "Black";
    char *res = ft_strjoin(s1, s2);
    
    if (res)
    {
        printf("Joined string: %s\n", res);
        free(res);
    }
    else
    {
        printf("Malloc failed or NULL input.\n");
    }
    return (0);
}*/