/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comprobations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:11:50 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 13:11:52 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	error_output(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	validate_integer_range(const char *str)
{
	long long	num;
	int		i;
	int		neg;
	long long	limit;

	if (!str)
		return (0);
	i = 0;
	neg = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	num = 0;
	limit = 2147483647LL;
	if (neg == 1)
		limit = 2147483648LL;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		if (num > limit)
			return (0);
		i++;
	}
	if (neg == 1)
		num = -num;
	if (num < -2147483648LL || num > 2147483647LL)
		return (0);
	return (1);
}

int search_duplicates(int *stack_a, int length)
{
  int i;
  int j;
  
  i = 0;
  while (i < length)
  {
    j = 0;
    while (j < length)
    {
      if (i != j)
        if (stack_a[i] == stack_a[j])
          return (1);
      j++;
    }
    i++;
  }
  return (0);
}

int stack_a_is_correct(char *stack_a)
{
  int i;
  int len;

  i = 0;
  len = ft_strlen(stack_a);
  while (stack_a[i] == ' ')
    i++;
  if(stack_a[i] != '-' && stack_a[i] != '+' && (stack_a[i] < '0' || stack_a[i] > '9'))
      return (1);
  if (stack_a[i] == '-' || stack_a[i] == '+')
    i++;
  if (i == len)
	return (1);
  while (i < len && stack_a[i] >= '0' && stack_a[i] <= '9')
    i++;
  while (i < len && (stack_a[i] == ' ' || (stack_a[i] >= 9 && stack_a[i] <= 13)))
    i++;
  if (i != len)
    return (1);
  return (0);
}

int *transform_argv(char **argv, int *length)
{
  int *stack_a;
  int i;
  int j;

  if (!argv || (*length) < 0)
    return (0);
  i = 0;
  j = 0;
  if (*length < 1)
    return (0);
  stack_a = malloc(sizeof(int) * (*length));
  if (!stack_a)
    return (0);
  while (j < (*length))
  {
    if(stack_a_is_correct(argv[i]) == 1)
    {
      free (stack_a);
      return (0);
    }
    if (validate_integer_range(argv[i]) == 0)
    {
      free (stack_a);
      return (0);
    }
    stack_a[j] = ft_atoi(argv[i]);
    i++;
    j++;
  }
  return (stack_a);
}

void	ft_array_to_list(int *array_a, t_list **stack_a, int length)
{
	t_list	*new_node;
	t_list	*actual_node;
	int	i;

	i = 0;
	while (i < length)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			return ;
		new_node->content = array_a[i];
		new_node->next = NULL;
		if (!*stack_a)
			*stack_a = new_node;
		else
		{
			actual_node = *stack_a;
			while (actual_node->next)
				actual_node = actual_node->next;
			actual_node->next = new_node;
		}
		i++;
	}
}
