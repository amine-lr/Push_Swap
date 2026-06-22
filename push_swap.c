/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:12:58 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 13:13:01 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_list(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

static int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	sort_two(t_list **stack_a, t_op_node **operations)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		sa(stack_a);
		record_operation(operations, "sa");
	}
}

static void	sort_three(t_list **stack_a, t_op_node **operations)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if (first > second && second < third && first < third)
	{
		sa(stack_a);
		record_operation(operations, "sa");
	}
	else if (first > second && second > third)
	{
		sa(stack_a);
		record_operation(operations, "sa");
		rra(stack_a);
		record_operation(operations, "rra");
	}
	else if (first > second && second < third && first > third)
	{
		ra(stack_a);
		record_operation(operations, "ra");
	}
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		record_operation(operations, "sa");
		ra(stack_a);
		record_operation(operations, "ra");
	}
	else if (first < second && second > third && first > third)
	{
		rra(stack_a);
		record_operation(operations, "rra");
	}
}

static int	find_min_position(t_list *stack)
{
	int	min;
	int	min_pos;
	int	current_pos;

	min = stack->content;
	min_pos = 0;
	current_pos = 0;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			min_pos = current_pos;
		}
		stack = stack->next;
		current_pos++;
	}
	return (min_pos);
}

static void	rotate_min_to_top(t_list **stack_a, int length,
		t_op_node **operations)
{
	int	min_pos;
	int	rotations;

	min_pos = find_min_position(*stack_a);
	if (min_pos <= length / 2)
	{
		while (min_pos-- > 0)
		{
			ra(stack_a);
			record_operation(operations, "ra");
		}
	}
	else
	{
		rotations = length - min_pos;
		while (rotations-- > 0)
		{
			rra(stack_a);
			record_operation(operations, "rra");
		}
	}
}

static void	sort_four_five(t_list **stack_a, t_list **stack_b, int length,
		t_op_node **operations)
{
	int	current_len;

	current_len = length;
	while (current_len > 3)
	{
		rotate_min_to_top(stack_a, current_len, operations);
		pb(stack_a, stack_b);
		record_operation(operations, "pb");
		current_len--;
	}
	if (!is_sorted(*stack_a))
		sort_three(stack_a, operations);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		record_operation(operations, "pa");
	}
}

static void	normalize_values(int *array, t_list *stack, int length)
{
	t_list	*current;
	int		i;
	int		j;
	int		rank;

	current = stack;
	i = 0;
	while (i < length)
	{
		rank = 0;
		j = 0;
		while (j < length)
		{
			if (array[j] < current->content)
				rank++;
			j++;
		}
		array[i] = rank;
		current->content = rank;
		current = current->next;
		i++;
	}
}

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
			normalize_values(array_a, stack_a, array_len);
			if (flags.strategy == SIMPLE)
				simple_sort(&stack_a, &stack_b, &operations);
			else if (flags.strategy == MEDIUM)
				medium_sort(&stack_a, &stack_b, &operations);
			else if (flags.strategy == COMPLEX)
				complex_sort(&stack_a, &stack_b, array_a, array_len, &operations);
			else if (flags.strategy == ADAPTIVE)
				adaptive_sort(&stack_a, &stack_b, array_a, array_len, &operations);
		}
	}
	print_operations(operations);
	if (flags.bench == 1)
	{
		benchmark_output(array_a, array_len, flags, operations);
	}
	free_list(stack_a);
	free_list(stack_b);
	free_operations(operations);
	free(array_a);
	return (0);
}
