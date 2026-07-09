#include "main_internal.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	normalize_values(int *array, t_list *stack, int length)
{
	t_list	*current;
	int		*copy;
	int		i;
	int		j;
	int		rank;

	copy = malloc(sizeof(int) * length);
	if (!copy)
		return (0);
	i = 0;
	while (i < length)
	{
		copy[i] = array[i];
		i++;
	}
	current = stack;
	i = 0;
	while (i < length)
	{
		rank = 0;
		j = 0;
		while (j < length)
		{
			if (copy[j] < current->content)
				rank++;
			j++;
		}
		array[i] = rank;
		current->content = rank;
		current = current->next;
		i++;
	}
	free(copy);
	return (1);
}
