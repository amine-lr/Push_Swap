/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:14:46 by molariou          #+#    #+#             */
/*   Updated: 2026/04/27 19:52:24 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*void ft_toupper_ifeven(unsigned int i, char *c)
{
	if (i % 2 == 0)
        *c = ft_toupper(*c);
}
int main()
{
    char s1[] = "hello world"; // Stored in a writable array
    ft_striteri(s1, ft_toupper_ifeven);
    printf("%s\n", s1); // Should print "HeLlO WoRlD"
    return (0);
}*/