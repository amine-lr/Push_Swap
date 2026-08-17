/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_disordered_pairs(int *array, int length)
{
	int	mistakes;
	int	first;
	int	second;

	mistakes = 0;
	first = 0;
	while (first < length)
	{
		second = first + 1;
		while (second < length)
		{
			if (array[first] > array[second])
				mistakes++;
			second++;
		}
		first++;
	}
	return (mistakes);
}

double	calculate_disorder_percentage(int *array, int length)
{
	int	total_pairs;

	if (length < 2)
		return (0.0);
	total_pairs = length * (length - 1) / 2;
	return ((double)count_disordered_pairs(array, length) / total_pairs);
}

void	adaptive_sort(t_sort_data *data)
{
	double	d;

	if (!data || !data->array)
		return ;
	d = calculate_disorder_percentage(data->array, data->length);
	if (d < 0.2)
	{
		/* Low disorder: use simple/specialized small-moves strategy */
		simple_sort(data->stack_a, data->stack_b, data->operations);
	}
	else if (d < 0.5)
	{
		/* Medium disorder */
		medium_sort(data->stack_a, data->stack_b, data->operations);
	}
	else
	{
		/* High disorder */
		complex_sort(data);
	}
}
