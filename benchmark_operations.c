/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_operations(t_op_node *ops, char *op_name)
{
	int	count;

	count = 0;
	while (ops)
	{
		if (!op_name || ft_strcmp(ops->operation, op_name) == 0)
			count++;
		ops = ops->next;
	}
	return (count);
}

static void	print_push_operations(t_op_node *ops)
{
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(count_operations(ops, NULL), 2);
	ft_putstr_fd("\n[bench] sa:  ", 2);
	ft_putnbr_fd(count_operations(ops, "sa"), 2);
	ft_putstr_fd("  sb:  ", 2);
	ft_putnbr_fd(count_operations(ops, "sb"), 2);
	ft_putstr_fd("  ss:  ", 2);
	ft_putnbr_fd(count_operations(ops, "ss"), 2);
	ft_putstr_fd("  pa:  ", 2);
	ft_putnbr_fd(count_operations(ops, "pa"), 2);
	ft_putstr_fd("  pb:  ", 2);
	ft_putnbr_fd(count_operations(ops, "pb"), 2);
}

static void	print_rotate_operations(t_op_node *ops)
{
	ft_putstr_fd("\n[bench] ra:  ", 2);
	ft_putnbr_fd(count_operations(ops, "ra"), 2);
	ft_putstr_fd("  rb:  ", 2);
	ft_putnbr_fd(count_operations(ops, "rb"), 2);
	ft_putstr_fd("  rr:  ", 2);
	ft_putnbr_fd(count_operations(ops, "rr"), 2);
	ft_putstr_fd("  rra:  ", 2);
	ft_putnbr_fd(count_operations(ops, "rra"), 2);
	ft_putstr_fd("  rrb:  ", 2);
	ft_putnbr_fd(count_operations(ops, "rrb"), 2);
	ft_putstr_fd("  rrr:  ", 2);
	ft_putnbr_fd(count_operations(ops, "rrr"), 2);
}

void	print_operation_counts(t_op_node *ops)
{
	print_push_operations(ops);
	print_rotate_operations(ops);
	write(2, "\n", 1);
}
