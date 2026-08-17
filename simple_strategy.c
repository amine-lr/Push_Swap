/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+#+#+#+#+  +#+          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_list **stack_a, t_list **stack_b, t_op_node **ops_head)
{
	int	minimum;

	while (*stack_a)
	{
		minimum = find_min_value(*stack_a);
		rotate_a_to_position(stack_a, find_position(*stack_a, minimum),
			ops_head);
		pb(stack_a, stack_b);
		record_operation(ops_head, "pb");
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		record_operation(ops_head, "pa");
	}
}
