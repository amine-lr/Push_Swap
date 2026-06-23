/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/20 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sqrt_approx(int n)
{
	int	result;

	if (n < 2)
		return (n);
	result = 1;
	while (result * result < n)
		result++;
	return (result);
}

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

void	medium_sort(t_list **stack_a, t_list **stack_b, t_op_node **ops_head)
{
	int	chunk_size;
	int	stack_len;
	int	current_chunk;
	int	range_start;
	int	range_end;
	int	chunk_count;

	if (!stack_a || !stack_b)
		return ;
	stack_len = stack_length(*stack_a);
	chunk_size = sqrt_approx(stack_len);
	chunk_count = (stack_len + chunk_size - 1) / chunk_size;
	current_chunk = 0;
	while (current_chunk < chunk_count && stack_length(*stack_a) > 0)
	{
		range_start = current_chunk * chunk_size;
		range_end = range_start + chunk_size - 1;
		if (range_end >= stack_len)
			range_end = stack_len - 1;
		if ((*stack_a)->content >= range_start && (*stack_a)->content <= range_end)
		{
			pb(stack_a, stack_b);
			record_operation(ops_head, "pb");
		}
		else
		{
			ra(stack_a);
			record_operation(ops_head, "ra");
		}
		if (stack_length(*stack_a) == 0)
			break ;
		current_chunk++;
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		record_operation(ops_head, "pa");
	}
}
