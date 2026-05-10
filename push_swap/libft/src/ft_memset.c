/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:12:18 by molariou          #+#    #+#             */
/*   Updated: 2026/04/25 13:12:18 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	size_t			i;
	unsigned char	*void_ptr;

	if (!ptr)
		return (NULL);
	void_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < len)
	{
		void_ptr[i] = c;
		i++;
	}
	return (ptr);
}

/*int main(void) 
{
	char str[] = "Hello, World!";
	char *str_ptr = NULL; 

	ft_memset(str, '8', 5);
	if (!str)
		printf("Received NULL pointer.\n");
	else
		printf("%s\n", str);
}*/
