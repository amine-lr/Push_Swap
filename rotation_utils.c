/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+#+#+#+#+  +#+          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_to_position(t_list **stack_a, int position,
		t_op_node **ops_head)
{
	int	length;

	length = stack_length(*stack_a);
	if (position <= length / 2)
	{
		while (position-- > 0)
		{
			ra(stack_a);
			record_operation(ops_head, "ra");
		}
	}
	else
	{
		position = length - position;
		while (position-- > 0)
		{
			rra(stack_a);
			record_operation(ops_head, "rra");
		}
	}
}

void	rotate_b_to_position(t_list **stack_b, int position,
		t_op_node **ops_head)
{
	int	length;

	length = stack_length(*stack_b);
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
}
