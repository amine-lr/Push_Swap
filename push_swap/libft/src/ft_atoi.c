/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:23:10 by molariou          #+#    #+#             */
/*   Updated: 2026/04/27 21:57:49 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			s;
	long long	res;

	i = 0;
	s = 1;
	res = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\t' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return ((res * s));
}
/*
int	main()
{
	const char	*str1 = NULL;
	const char	*str2 = "      \n	-2465rfrrg";

	int	num1 = ft_atoi(str1);
	int	num2 = ft_atoi(str2);
	printf("converted number : %d\n", num1);
	printf("converted number : %d\n", num2);
	return (0);
}*/
