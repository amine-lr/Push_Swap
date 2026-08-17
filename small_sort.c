/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+#+#+#+#+   +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:12:58 by jangonza          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack_a, t_op_node **operations)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		sa(stack_a);
		record_operation(operations, "sa");
	}
}

static void	exec_op(t_list **stack_a, t_op_node **ops, char *op)
{
	if (op[0] == 'r' && op[1] == 'a')
		ra(stack_a);
	else if (op[0] == 'r' && op[1] == 'r')
		rra(stack_a);
	else
		sa(stack_a);
	record_operation(ops, op);
}

void	sort_three(t_list **stack_a, t_op_node **ops)
{
	int	a;
	int	b;
	int	c;

	while (!is_sorted(*stack_a))
	{
		a = (*stack_a)->content;
		b = (*stack_a)->next->content;
		c = (*stack_a)->next->next->content;
		if (a > b && a > c)
			exec_op(stack_a, ops, "ra");
		else if (b > a && b > c)
			exec_op(stack_a, ops, "rra");
		else
			exec_op(stack_a, ops, "sa");
	}
}

void	sort_four_five(t_list **stack_a, t_list **stack_b, int length,
		t_op_node **operations)
{
	int	current_length;

	current_length = length;
	while (current_length > 3)
	{
		rotate_min_to_top(stack_a, current_length, operations);
		pb(stack_a, stack_b);
		record_operation(operations, "pb");
		current_length--;
	}
	if (!is_sorted(*stack_a))
		sort_three(stack_a, operations);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		record_operation(operations, "pa");
	}
}
