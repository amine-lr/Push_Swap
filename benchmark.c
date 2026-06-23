#include "push_swap.h"

static int	count_operations(t_op_node *ops, char *op_name)
{
	int	count;

	count = 0;
	while (ops)
	{
		if (ft_strcmp(ops->operation, op_name) == 0)
			count++;
		ops = ops->next;
	}
	return (count);
}

static int	total_operations(t_op_node *ops)
{
	int	count;

	count = 0;
	while (ops)
	{
		count++;
		ops = ops->next;
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
	return ("adaptive");
}

static char	*complexity_name(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("O(n^2)");
	if (strategy == MEDIUM)
		return ("O(n sqrt n)");
	if (strategy == COMPLEX)
		return ("O(n log n)");
	return ("adaptive");
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

void	benchmark_output(int *array, int length, t_flags flags, t_op_node *ops)
{
	double	disorder;

	if (flags.bench == 0)
		return ;
	disorder = calculate_disorder_percentage(array, length);
	ft_putstr_fd("\n=== BENCHMARK ===\nDisorder: ", 2);
	print_percent(disorder);
	ft_putstr_fd("\nStrategy: ", 2);
	ft_putstr_fd(strategy_name(flags.strategy), 2);
	ft_putstr_fd(" (", 2);
	ft_putstr_fd(complexity_name(flags.strategy), 2);
	ft_putstr_fd(")\nTotal operations: ", 2);
	ft_putnbr_fd(total_operations(ops), 2);
	ft_putstr_fd("\nsa: ", 2);
	ft_putnbr_fd(count_operations(ops, "sa"), 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(count_operations(ops, "sb"), 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(count_operations(ops, "ss"), 2);
	ft_putstr_fd("\npa: ", 2);
	ft_putnbr_fd(count_operations(ops, "pa"), 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(count_operations(ops, "pb"), 2);
	ft_putstr_fd("\nra: ", 2);
	ft_putnbr_fd(count_operations(ops, "ra"), 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(count_operations(ops, "rb"), 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(count_operations(ops, "rr"), 2);
	ft_putstr_fd("\nrra: ", 2);
	ft_putnbr_fd(count_operations(ops, "rra"), 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(count_operations(ops, "rrb"), 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(count_operations(ops, "rrr"), 2);
	write(2, "\n", 1);
}
