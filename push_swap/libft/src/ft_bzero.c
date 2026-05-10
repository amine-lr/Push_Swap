/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:23:15 by molariou          #+#    #+#             */
/*   Updated: 2026/04/25 14:23:31 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
/*int main(void)
{
    char    *str = NULL;
    int     len = 5;

    printf("--- Testing ft_bzero with NULL ---\n");
    ft_bzero(str, len);
    printf("1. ft_bzero called successfully (no crash).\n");
    if (str == NULL)
    {
        printf("2. Pointer is still NULL as expected.\n");
    }
    else
      printf("2. Result: %s\n", str);
    printf("--- Test Complete ---\n");
    return (0);
}*/