/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_position(t_list *stack, int *length)
{
	int	max;
	int	max_position;
	int	position;

	max = stack->content;
	max_position = 0;
	position = 0;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			max_position = position;
		}
		stack = stack->next;
		position++;
	}
	*length = position;
	return (max_position);
}

static void	move_max_to_a(t_list **stack_a, t_list **stack_b,
		t_op_node **ops_head)
{
	int	length;
	int	position;

	position = find_max_position(*stack_b, &length);
	if (position <= length / 2)
	{
		while (position-- > 0)
		{
			rb(stack_b);
			record_operation(ops_head, "rb");
		}
	}
	else
	{
		position = length - position;
		while (position-- > 0)
		{
			rrb(stack_b);
			record_operation(ops_head, "rrb");
		}
	}
	pa(stack_a, stack_b);
	record_operation(ops_head, "pa");
}

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

static void	distribute_to_b(t_list **stack_a, t_list **stack_b,
		int window, t_op_node **ops_head)
{
	int	index;

	index = 0;
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
}

void	complex_sort(t_sort_data *data)
{
	int	window;

	if (!data || !data->stack_a || !data->stack_b || data->length < 2)
		return ;
	window = 1;
	while (window * window < data->length)
		window++;
	window = (window * 13) / 10;
	distribute_to_b(data->stack_a, data->stack_b, window, data->operations);
	while (*data->stack_b)
	{
		move_max_to_a(data->stack_a, data->stack_b, data->operations);
	}
}
