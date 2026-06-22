/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/20 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_position(t_list *stack_b)
{
	int		max;
	int		pos;
	int		current_pos;
	t_list	*temp;

	if (!stack_b)
		return (-1);
	max = stack_b->content;
	pos = 0;
	current_pos = 0;
	temp = stack_b;
	while (temp)
	{
		if (temp->content > max)
		{
			max = temp->content;
			pos = current_pos;
		}
		temp = temp->next;
		current_pos++;
	}
	return (pos);
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

static void	insert_element(t_list **stack_a, t_list **stack_b, t_op_node **ops_head)
{
	int	max_pos;
	int	stack_b_len;
	int	rotations;

	max_pos = find_max_position(*stack_b);
	stack_b_len = stack_length(*stack_b);
	rotations = stack_b_len - max_pos;
	while (rotations > 0)
	{
		rb(stack_b);
		record_operation(ops_head, "rb");
		rotations--;
	}
	pa(stack_a, stack_b);
	record_operation(ops_head, "pa");
}

void	simple_sort(t_list **stack_a, t_list **stack_b, t_op_node **ops_head)
{
	int	stack_a_len;
	int	i;

	if (!stack_a || !stack_b)
		return ;
	stack_a_len = stack_length(*stack_a);
	i = 0;
	while (i < stack_a_len)
	{
		pb(stack_a, stack_b);
		record_operation(ops_head, "pb");
		if (*stack_b && (*stack_b)->next && (*stack_b)->content < (*stack_b)->next->content)
		{
			sb(stack_b);
			record_operation(ops_head, "sb");
		}
		i++;
	}
	while (*stack_b)
	{
		insert_element(stack_a, stack_b, ops_head);
	}
}
