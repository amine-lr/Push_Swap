/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:12:58 by jangonza          #+#    #+#             */
/*   Updated: 2026/08/17 13:07:02 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	initialize_data(int argc, char **argv, t_flags *flags,
		t_sort_data *data)
{
	int	start_index;

	*flags = parse_flags(argc, argv, &start_index);
	data->length = argc - start_index;
	if (data->length < 1)
		return (0);
	data->array = transform_argv(&argv[start_index], &data->length);
	if (!data->array || search_duplicates(data->array, data->length))
	{
		free(data->array);
		return (0);
	}
	data->stack_a = malloc(sizeof(t_list *));
	data->stack_b = malloc(sizeof(t_list *));
	data->operations = malloc(sizeof(t_op_node *));
	if (!data->stack_a || !data->stack_b || !data->operations)
		return (0);
	*data->stack_a = NULL;
	*data->stack_b = NULL;
	*data->operations = NULL;
	return (1);
}

static void	sort_data(t_flags flags, t_sort_data *data)
{
	if (is_sorted(*data->stack_a))
		return ;
	if (data->length == 2)
		sort_two(data->stack_a, data->operations);
	else if (data->length == 3)
		sort_three(data->stack_a, data->operations);
	else if (data->length <= 5)
		sort_four_five(data->stack_a, data->stack_b, data->length,
			data->operations);
	else if (normalize_values(data->array, *data->stack_a, data->length))
		run_strategy(flags, data);
}

static void	free_data(t_sort_data *data)
{
	free_list(*data->stack_a);
	free_list(*data->stack_b);
	free_operations(*data->operations);
	free(data->stack_a);
	free(data->stack_b);
	free(data->operations);
	free(data->array);
}

int	main(int argc, char *argv[])
{
	t_flags		flags;
	t_sort_data	data;
	t_strategy	act_strat;

	if (argc < 2)
		return (0);
	if (!initialize_data(argc, argv, &flags, &data))
		error_output();
	act_strat = flags.strategy;
	if (data.length <= 5)
		act_strat = ADAPTIVE_SIMPLE;
	else if (flags.strategy == ADAPTIVE && data.length > 5)
	{
		if (calculate_disorder_percentage(data.array, data.length) < 0.5)
			act_strat = ADAPTIVE_MEDIUM;
		else
			act_strat = ADAPTIVE_COMPLEX;
	}
	ft_array_to_list(data.array, data.stack_a, data.length);
	sort_data(flags, &data);
	print_operations(*data.operations);
	if (flags.bench)
		benchmark_output(data.array, data.length, act_strat, *data.operations);
	free_data(&data);
	return (0);
}
