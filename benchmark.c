/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/08/17 13:07:42 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*strategy_name(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("Simple");
	if (strategy == MEDIUM)
		return ("Medium");
	if (strategy == COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

static char	*complexity_name(t_strategy strategy)
{
	if (strategy == SIMPLE || strategy == ADAPTIVE_SIMPLE)
		return ("O(n^2)");
	if (strategy == MEDIUM || strategy == ADAPTIVE_MEDIUM)
		return ("O(n sqrt n)");
	if (strategy == COMPLEX || strategy == ADAPTIVE_COMPLEX)
		return ("O(n log n)");
	return ("Adaptive");
}

static void	print_percent(double value)
{
	int	percent;

	percent = (int)(value * 10000.0);
	ft_putnbr_fd(percent / 100, 2);
	write(2, ".", 1);
	if ((percent % 100) < 10)
		write(2, "0", 1);
	ft_putnbr_fd(percent % 100, 2);
	write(2, "%", 1);
}

void	benchmark_output(int *array, int length, t_strategy strategy,
	t_op_node *ops)
{
	double	disorder;

	disorder = calculate_disorder_percentage(array, length);
	ft_putstr_fd("[bench] disorder: ", 2);
	print_percent(disorder);
	ft_putstr_fd("\n[bench] strategy: ", 2);
	ft_putstr_fd(strategy_name(strategy), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(complexity_name(strategy), 2);
	ft_putstr_fd("\n", 2);
	print_operation_counts(ops);
}
