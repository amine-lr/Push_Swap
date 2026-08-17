/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+#+#+#+#+  +#+          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_list **stack_a, t_list **stack_b,
		t_op_node **ops_head, int rotate)
{
	pb(stack_a, stack_b);
	record_operation(ops_head, "pb");
	if (rotate && (*stack_b)->next)
	{
		rb(stack_b);
		record_operation(ops_head, "rb");
	}
}

static void	return_to_a(t_list **stack_a, t_list **stack_b,
		t_op_node **ops_head)
{
	int	maximum;

	while (*stack_b)
	{
		maximum = find_max_value(*stack_b);
		rotate_b_to_position(stack_b, find_position(*stack_b, maximum),
			ops_head);
		pa(stack_a, stack_b);
		record_operation(ops_head, "pa");
	}
}

void	medium_sort(t_list **stack_a, t_list **stack_b, t_op_node **ops_head)
{
	int	index;
	int	window;

	index = 0;
	window = chunk_size(stack_length(*stack_a));
	while (*stack_a)
	{
		if ((*stack_a)->content <= index)
		{
			push_to_b(stack_a, stack_b, ops_head, 1);
			index++;
		}
		else if ((*stack_a)->content <= index + window)
		{
			push_to_b(stack_a, stack_b, ops_head, 0);
			index++;
		}
		else
		{
			ra(stack_a);
			record_operation(ops_head, "ra");
		}
	}
	return_to_a(stack_a, stack_b, ops_head);
}
