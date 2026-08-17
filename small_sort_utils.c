/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+#+#+#+#+   +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_position(t_list *stack)
{
	int	min;
	int	min_position;
	int	position;

	min = stack->content;
	min_position = 0;
	position = 0;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			min_position = position;
		}
		stack = stack->next;
		position++;
	}
	return (min_position);
}

static void	rotate_up(t_list **stack_a, int rotations,
		t_op_node **operations)
{
	while (rotations-- > 0)
	{
		ra(stack_a);
		record_operation(operations, "ra");
	}
}

static void	rotate_down(t_list **stack_a, int rotations,
		t_op_node **operations)
{
	while (rotations-- > 0)
	{
		rra(stack_a);
		record_operation(operations, "rra");
	}
}

void	rotate_min_to_top(t_list **stack_a, int length,
		t_op_node **operations)
{
	int	min_position;

	min_position = find_min_position(*stack_a);
	if (min_position <= length / 2)
		rotate_up(stack_a, min_position, operations);
	else
		rotate_down(stack_a, length - min_position, operations);
}
