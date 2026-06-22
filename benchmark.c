/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/20 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_operations(t_op_node *ops, char *op_name)
{
	int		count;
	t_op_node	*temp;

	count = 0;
	temp = ops;
	while (temp)
	{
		if (ft_strcmp(temp->operation, op_name) == 0)
			count++;
		temp = temp->next;
	}
	return (count);
}

static int	total_operations(t_op_node *ops)
{
	int		count;
	t_op_node	*temp;

	count = 0;
	temp = ops;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

static char	*strategy_name(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("simple");
	if (strategy == MEDIUM)
		return ("medium");
	if (strategy == COMPLEX)
		return ("complex");
	if (strategy == ADAPTIVE)
		return ("adaptive");
	return ("unknown");
}

static char	*complexity_class(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("O(n²)");
	if (strategy == MEDIUM)
		return ("O(n√n)");
	if (strategy == COMPLEX)
		return ("O(n log n)");
	if (strategy == ADAPTIVE)
		return ("O(n log n)");
	return ("unknown");
}

void	benchmark_output(int *array, int length, t_flags flags, t_op_node *ops)
{
	double	disorder;
	int		total_ops;

	disorder = calculate_disorder_percentage(array, length);
	write(2, "\n=== BENCHMARK ===\n", 19);
	write(2, "Disorder: ", 10);
	ft_putnbr_fd((int)(disorder * 100), 2);
	write(2, "%\nStrategy: ", 12);
	write(2, strategy_name(flags.strategy), ft_strlen(strategy_name(flags.strategy)));
	write(2, " (", 2);
	write(2, complexity_class(flags.strategy), ft_strlen(complexity_class(flags.strategy)));
	write(2, ")\nTotal operations: ", 20);
	total_ops = total_operations(ops);
	ft_putnbr_fd(total_ops, 2);
	write(2, "\nOperation breakdown:\n", 22);
	write(2, "  sa: ", 6);
	ft_putnbr_fd(count_operations(ops, "sa"), 2);
	write(2, " | sb: ", 7);
	ft_putnbr_fd(count_operations(ops, "sb"), 2);
	write(2, " | ss: ", 7);
	ft_putnbr_fd(count_operations(ops, "ss"), 2);
	write(2, "\n  pa: ", 7);
	ft_putnbr_fd(count_operations(ops, "pa"), 2);
	write(2, " | pb: ", 7);
	ft_putnbr_fd(count_operations(ops, "pb"), 2);
	write(2, "\n  ra: ", 7);
	ft_putnbr_fd(count_operations(ops, "ra"), 2);
	write(2, " | rb: ", 7);
	ft_putnbr_fd(count_operations(ops, "rb"), 2);
	write(2, " | rr: ", 7);
	ft_putnbr_fd(count_operations(ops, "rr"), 2);
	write(2, "\n  rra: ", 8);
	ft_putnbr_fd(count_operations(ops, "rra"), 2);
	write(2, " | rrb: ", 8);
	ft_putnbr_fd(count_operations(ops, "rrb"), 2);
	write(2, " | rrr: ", 8);
	ft_putnbr_fd(count_operations(ops, "rrr"), 2);
	write(2, "\n", 1);
}
