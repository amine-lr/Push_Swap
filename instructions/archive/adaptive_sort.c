/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/20 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calculate_disorder_percentage(int *array, int length)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	if (length < 2)
		return (0.0);
	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			total_pairs++;
			if (array[i] > array[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

void	adaptive_sort(t_list **stack_a, t_list **stack_b, 
		int *array, int length, t_op_node **ops_head)
{
	if (!stack_a || !stack_b || !array || length < 2)
		return ;
	complex_sort(stack_a, stack_b, array, length, ops_head);
}
