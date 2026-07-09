/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/20 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_op_node	*create_op_node(char *op_name)
{
	t_op_node	*new_node;

	new_node = malloc(sizeof(t_op_node));
	if (!new_node)
		return (NULL);
	new_node->operation = op_name;
	new_node->next = NULL;
	return (new_node);
}

void	record_operation(t_op_node **ops_head, char *op_name)
{
	t_op_node	*new_node;
	t_op_node	*current;

	if (!ops_head)
		return ;
	new_node = create_op_node(op_name);
	if (!new_node)
		return ;
	if (!*ops_head)
	{
		*ops_head = new_node;
		return ;
	}
	current = *ops_head;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

void	print_operations(t_op_node *ops_head)
{
	t_op_node	*current;

	current = ops_head;
	while (current)
	{
		write(1, current->operation, ft_strlen(current->operation));
		write(1, "\n", 1);
		current = current->next;
	}
}

void	free_operations(t_op_node *ops_head)
{
	t_op_node	*current;
	t_op_node	*temp;

	current = ops_head;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}
