#include "push_swap.h"

static int	stack_length(t_list *stack)
{
	int	length;

	length = 0;
	while (stack)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

static int	find_position(t_list *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->content == value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (0);
}

static int	find_min_value(t_list *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

static int	find_max_value(t_list *stack)
{
	int	max;

	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

static void	rotate_a_to_position(t_list **stack_a, int pos,
		t_op_node **ops_head)
{
	int	length;

	length = stack_length(*stack_a);
	if (pos <= length / 2)
	{
		while (pos-- > 0)
		{
			ra(stack_a);
			record_operation(ops_head, "ra");
		}
	}
	else
	{
		pos = length - pos;
		while (pos-- > 0)
		{
			rra(stack_a);
			record_operation(ops_head, "rra");
		}
	}
}

static void	rotate_b_to_position(t_list **stack_b, int pos,
		t_op_node **ops_head)
{
	int	length;

	length = stack_length(*stack_b);
	if (pos <= length / 2)
	{
		while (pos-- > 0)
		{
			rb(stack_b);
			record_operation(ops_head, "rb");
		}
	}
	else
	{
		pos = length - pos;
		while (pos-- > 0)
		{
			rrb(stack_b);
			record_operation(ops_head, "rrb");
		}
	}
}

void	simple_sort(t_list **stack_a, t_list **stack_b, t_op_node **ops_head)
{
	int	min;
	int	pos;

	while (*stack_a)
	{
		min = find_min_value(*stack_a);
		pos = find_position(*stack_a, min);
		rotate_a_to_position(stack_a, pos, ops_head);
		pb(stack_a, stack_b);
		record_operation(ops_head, "pb");
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		record_operation(ops_head, "pa");
	}
}

static int	chunk_size(int length)
{
	int	size;

	size = 1;
	while (size * size < length)
		size++;
	if (length > 100)
		size = size * 2;
	else
		size = size + (size / 2);
	return (size);
}

void	medium_sort(t_list **stack_a, t_list **stack_b, t_op_node **ops_head)
{
	int	index;
	int	window;
	int	max;
	int	pos;

	index = 0;
	window = chunk_size(stack_length(*stack_a));
	while (*stack_a)
	{
		if ((*stack_a)->content <= index)
		{
			pb(stack_a, stack_b);
			record_operation(ops_head, "pb");
			if (*stack_b && (*stack_b)->next)
			{
				rb(stack_b);
				record_operation(ops_head, "rb");
			}
			index++;
		}
		else if ((*stack_a)->content <= index + window)
		{
			pb(stack_a, stack_b);
			record_operation(ops_head, "pb");
			index++;
		}
		else
		{
			ra(stack_a);
			record_operation(ops_head, "ra");
		}
	}
	while (*stack_b)
	{
		max = find_max_value(*stack_b);
		pos = find_position(*stack_b, max);
		rotate_b_to_position(stack_b, pos, ops_head);
		pa(stack_a, stack_b);
		record_operation(ops_head, "pa");
	}
}

double	calculate_disorder_percentage(int *array, int length)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	if (length < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			total_pairs++;
			if (array[i] > array[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / (double)total_pairs);
}

void	adaptive_sort(t_list **stack_a, t_list **stack_b, int *array,
		int length, t_op_node **ops_head)
{
	double	disorder;

	disorder = calculate_disorder_percentage(array, length);
	if (disorder < 0.5)
		medium_sort(stack_a, stack_b, ops_head);
	else
		complex_sort(stack_a, stack_b, array, length, ops_head);
}
