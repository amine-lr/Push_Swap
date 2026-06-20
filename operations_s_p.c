/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:44:08 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 12:44:10 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sa(t_list **stack_a)
{
	int	i;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	i = *(int *)(*stack_a)->content;
	*(int *)(*stack_a)->content = *(int *)(*stack_a)->next->content;
	*(int *)(*stack_a)->next->content = i;
}

void	sb(t_list **stack_b)
{
	int	i;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	i = *(int *)(*stack_b)->content;
	*(int *)(*stack_b)->content = *(int *)(*stack_b)->next->content;
	*(int *)(*stack_b)->next->content = i;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*moving_node;

	if (!stack_b || !*stack_b)
		return ;
	moving_node = *stack_b;
	*stack_b = (*stack_b)->next;
	moving_node->next = *stack_a;
	*stack_a = moving_node;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*moving_node;

	if (!stack_a || !*stack_a)
		return ;
	moving_node = *stack_a;
	*stack_a = (*stack_a)->next;
	moving_node->next = *stack_b;
	*stack_b = moving_node;
}
