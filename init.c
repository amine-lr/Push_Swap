/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:12:58 by jangonza          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	get_rank(int *copy, int value, int length)
{
	int	index;
	int	rank;

	index = 0;
	rank = 0;
	while (index < length)
	{
		if (copy[index] < value)
			rank++;
		index++;
	}
	return (rank);
}

static int	*copy_values(int *array, int length)
{
	int	*copy;
	int	index;

	copy = malloc(sizeof(int) * length);
	if (!copy)
		return (NULL);
	index = 0;
	while (index < length)
	{
		copy[index] = array[index];
		index++;
	}
	return (copy);
}

int	normalize_values(int *array, t_list *stack, int length)
{
	int	*copy;
	int	index;

	copy = copy_values(array, length);
	if (!copy)
		return (0);
	index = 0;
	while (index < length)
	{
		array[index] = get_rank(copy, stack->content, length);
		stack->content = array[index];
		stack = stack->next;
		index++;
	}
	free(copy);
	return (1);
}
