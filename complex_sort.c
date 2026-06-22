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
	t_list	*temp;

	length = 0;
	temp = stack;
	while (temp)
	{
		length++;
		temp = temp->next;
	}
	return (length);
}

static int	find_max_bits(int *array, int length)
{
	int	max;
	int	bits;
	int	i;

	max = 0;
	i = 0;
	while (i < length)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	bits = 0;
	if (max == 0)
		return (1);
	while (max > 0)
	{
		bits++;
		max = max >> 1;
	}
	return (bits);
}

static void	radix_pass(t_list **stack_a, t_list **stack_b, 
		int bit_pos, t_op_node **ops_head)
{
	int	length;
	int	i;

	length = stack_length(*stack_a);
	i = 0;
	while (i < length)
	{
		if (((*stack_a)->content >> bit_pos) & 1)
		{
			ra(stack_a);
			record_operation(ops_head, "ra");
		}
		else
		{
			pb(stack_a, stack_b);
			record_operation(ops_head, "pb");
		}
		i++;
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		record_operation(ops_head, "pa");
	}
}

void	complex_sort(t_list **stack_a, t_list **stack_b, 
		int *array, int length, t_op_node **ops_head)
{
	int	max_bits;
	int	bit_pos;

	if (!stack_a || !stack_b || !array || length < 2)
		return ;
	max_bits = find_max_bits(array, length);
	bit_pos = 0;
	while (bit_pos < max_bits)
	{
		radix_pass(stack_a, stack_b, bit_pos, ops_head);
		bit_pos++;
	}
}
