/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:09:40 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 13:09:43 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void rra(t_list **stack_a)
{
	t_list *prev;
	t_list *last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return;
	prev = NULL;
	last = *stack_a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}

void	rrb(t_list **stack_b)
{
	t_list *prev;
	t_list *last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return;
	prev = NULL;
	last = *stack_b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
