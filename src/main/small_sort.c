#include "main_internal.h"

void	sort_two(t_list **stack_a, t_op_node **operations)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		sa(stack_a);
		record_operation(operations, "sa");
	}
}

void	sort_three(t_list **stack_a, t_op_node **operations)
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

void	rotate_min_to_top(t_list **stack_a, int length,
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

void	sort_four_five(t_list **stack_a, t_list **stack_b, int length,
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
