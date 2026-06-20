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


int calculate_disorder(int *stack_a, int length)
{
  int mistakes;
  int total_pairs;
  int i;
  int j;

  i = 0;
  mistakes = 0;
  total_pairs = 0;

  while (i < length)
  {
    j = i + 1;
    while (j < length)
    {
      total_pairs++;
      if (stack_a[i] > stack_a[j])
        mistakes++;
      j++;
    }
    i++;
  }
  return ((mistakes * 100)/total_pairs);
}

void  push_swap(int *stack_a, int length)
{
  int *stack_b;
  int disorder_index;

  if(search_duplicates(stack_a, length) == 1 || length < 2)
    return ;
  disorder_index = calculate_disorder(stack_a, length);
}

int main(int argc, char *argv[])
{
	int *array_a;
	t_list	*stack_a;

	stack_a = malloc(sizeof(t_list));
	if (!stack_a)
		return (NULL);
	array_a = transform_argv(argv, (argc - 1));
	if(!array_a)
		return (1);
	ft_array_to_list(array_a, stack_a, (argc - 1));
	push_swap(stack_a, (argc - 1));
	return (0);
}
