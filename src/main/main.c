/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:12:58 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 13:13:01 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_internal.h"

int	main(int argc, char *argv[])
{
	t_flags		flags;
	t_list		*stack_a;
	t_list		*stack_b;
	int			*array_a;
	int			array_len;
	int			start_index;
	t_op_node	*operations;

	if (argc < 2)
		return (0);
	flags = parse_flags(argc, argv, &start_index);
	array_len = argc - start_index;
	if (array_len < 1)
		return (0);
	array_a = transform_argv(&argv[start_index], &array_len);
	if (!array_a)
		error_output();
	if (search_duplicates(array_a, array_len) == 1)
	{
		free(array_a);
		error_output();
	}
	stack_a = NULL;
	stack_b = NULL;
	operations = NULL;
	ft_array_to_list(array_a, &stack_a, array_len);
	if (!is_sorted(stack_a))
	{
		if (array_len == 2)
			sort_two(&stack_a, &operations);
		else if (array_len == 3)
			sort_three(&stack_a, &operations);
		else if (array_len <= 5)
			sort_four_five(&stack_a, &stack_b, array_len, &operations);
		else
		{
			if (!normalize_values(array_a, stack_a, array_len))
			{
				free_list(stack_a);
				free(array_a);
				error_output();
			}
			run_strategy(flags, &stack_a, &stack_b, array_a, array_len,
				&operations);
		}
	}
	print_operations(operations);
	benchmark_output(array_a, array_len, flags, operations);
	free_list(stack_a);
	free_list(stack_b);
	free_operations(operations);
	free(array_a);
	return (0);
}
