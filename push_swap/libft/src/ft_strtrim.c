/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 20:17:35 by molariou          #+#    #+#             */
/*   Updated: 2026/04/27 21:57:48 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	tr_len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	len = ft_strlen(s1);
	while (len && ft_strrchr(set, s1[len - 1]))
		len --;
	tr_len = len - i;
	return (ft_substr(s1, i, tr_len));
}
/*
int	main ()
{
	char *str = "amineam";
	char *set = NULL;
	printf("%s", ft_strtrim(str,set));
}*/