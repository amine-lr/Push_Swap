/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/08/17 12:51:38 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_list *stack)
{
	int	length;

	length = 0;
	while (stack)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

int	find_position(t_list *stack, int value)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->content == value)
			return (position);
		stack = stack->next;
		position++;
	}
	return (0);
}

int	find_min_value(t_list *stack)
{
	int	minimum;

	minimum = stack->content;
	while (stack)
	{
		if (stack->content < minimum)
			minimum = stack->content;
		stack = stack->next;
	}
	return (minimum);
}

int	find_max_value(t_list *stack)
{
	int	maximum;

	maximum = stack->content;
	while (stack)
	{
		if (stack->content > maximum)
			maximum = stack->content;
		stack = stack->next;
	}
	return (maximum);
}

int	chunk_size(int length)
{
	int	size;

	size = 1;
	while (size * size < length)
		size++;
	if (length > 100)
		size *= 2;
	else
		size += size / 2;
	return (size);
}
