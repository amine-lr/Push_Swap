/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comprobations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:11:50 by jangonza          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	skip_spaces(const char *str)
{
	int	index;

	index = 0;
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	return (index);
}

void	error_output(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	validate_integer_range(const char *str)
{
	long long	number;
	long long	limit;
	int			index;

	if (!str)
		return (0);
	index = skip_spaces(str);
	limit = 2147483647LL + (str[index] == '-');
	if (str[index] == '-' || str[index] == '+')
		index++;
	if (str[index] < '0' || str[index] > '9')
		return (0);
	number = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		number = (number * 10) + (str[index] - '0');
		if (number > limit)
			return (0);
		index++;
	}
	return (1);
}

int	search_duplicates(int *stack_a, int length)
{
	int	index;
	int	compare_index;

	index = 0;
	while (index < length)
	{
		compare_index = index + 1;
		while (compare_index < length)
		{
			if (stack_a[index] == stack_a[compare_index])
				return (1);
			compare_index++;
		}
		index++;
	}
	return (0);
}

int	stack_a_is_correct(char *stack_a)
{
	int	index;

	if (!stack_a || !validate_integer_range(stack_a))
		return (1);
	index = skip_spaces(stack_a);
	if (stack_a[index] == '-' || stack_a[index] == '+')
		index++;
	while (stack_a[index] >= '0' && stack_a[index] <= '9')
		index++;
	while (stack_a[index] == ' ' || (stack_a[index] >= 9
			&& stack_a[index] <= 13))
		index++;
	return (stack_a[index] != '\0');
}
