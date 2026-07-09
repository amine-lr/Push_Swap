#include "main_internal.h"

void	run_strategy(t_flags flags, t_list **stack_a, t_list **stack_b,
		int *array_a, int array_len, t_op_node **operations)
{
	if (flags.strategy == SIMPLE)
		simple_sort(stack_a, stack_b, operations);
	else if (flags.strategy == MEDIUM)
		medium_sort(stack_a, stack_b, operations);
	else if (flags.strategy == COMPLEX)
		complex_sort(stack_a, stack_b, array_a, array_len, operations);
	else
		adaptive_sort(stack_a, stack_b, array_a, array_len, operations);
}
