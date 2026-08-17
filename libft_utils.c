/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+#+#+#+#+  +#+          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:10:21 by jangonza          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	ft_atoi(const char *str)
{
	long	value;
	int		index;
	int		sign;

	index = 0;
	sign = 1;
	value = 0;
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		value = (value * 10) + (str[index] - '0');
		index++;
	}
	return ((int)(value * sign));
}

void	ft_putnbr_fd(int number, int fd)
{
	long	value;
	char	character;

	value = number;
	if (value < 0)
	{
		write(fd, "-", 1);
		value = -value;
	}
	if (value < 10)
	{
		character = value + '0';
		write(fd, &character, 1);
	}
	else
	{
		ft_putnbr_fd(value / 10, fd);
		character = (value % 10) + '0';
		write(fd, &character, 1);
	}
}

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
}
