/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/20 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_length(t_list *stack)
{
	int		length;

	length = 0;
	while (stack)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

static int	sqrt_approx(int n)
{
	int	result;

	result = 1;
	while (result * result < n)
		result++;
	return (result);
}

static int	find_max_position(t_list *stack)
{
	int	max;
	int	max_pos;
	int	pos;

	max = stack->content;
	max_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max_pos);
}

static void	rotate_b_to_max(t_list **stack_b, t_op_node **ops_head)
{
	int	length;
	int	pos;

	length = stack_length(*stack_b);
	pos = find_max_position(*stack_b);
	if (pos <= length / 2)
	{
		while (pos-- > 0)
		{
			rb(stack_b);
			record_operation(ops_head, "rb");
		}
	}
	else
	{
		pos = length - pos;
		while (pos-- > 0)
		{
			rrb(stack_b);
			record_operation(ops_head, "rrb");
		}
	}
}

void	complex_sort(t_list **stack_a, t_list **stack_b, 
		int *array, int length, t_op_node **ops_head)
{
	int	index;
	int	window;

	if (!stack_a || !stack_b || !array || length < 2)
		return ;
	index = 0;
	window = (sqrt_approx(length) * 13) / 10;
	if (window < 1)
		window = 1;
	while (*stack_a)
	{
		if ((*stack_a)->content <= index)
		{
			pb(stack_a, stack_b);
			record_operation(ops_head, "pb");
			if (*stack_b && (*stack_b)->next)
			{
				rb(stack_b);
				record_operation(ops_head, "rb");
			}
			index++;
		}
		else if ((*stack_a)->content <= index + window)
		{
			pb(stack_a, stack_b);
			record_operation(ops_head, "pb");
			index++;
		}
		else
		{
			ra(stack_a);
			record_operation(ops_head, "ra");
		}
	}
	while (*stack_b)
	{
		rotate_b_to_max(stack_b, ops_head);
		pa(stack_a, stack_b);
		record_operation(ops_head, "pa");
	}
}
