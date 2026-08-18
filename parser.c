/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:11:50 by jangonza          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_known_flag(char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (1);
	if (ft_strcmp(arg, "--medium") == 0)
		return (1);
	if (ft_strcmp(arg, "--complex") == 0)
		return (1);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (1);
	if (ft_strcmp(arg, "--bench") == 0)
		return (1);
	return (0);
}

static void	apply_flag(t_flags *flags, char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		flags->strategy = SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		flags->strategy = MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		flags->strategy = COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		flags->strategy = ADAPTIVE;
	else if (ft_strcmp(arg, "--bench") == 0)
		flags->bench = 1;
}

t_flags	parse_flags(int argc, char **argv, int *start_index)
{
	t_flags	flags;
	int		index;

	flags.strategy = ADAPTIVE;
	flags.bench = 0;
	index = 1;
	while (index < argc && is_known_flag(argv[index]))
	{
		apply_flag(&flags, argv[index]);
		index++;
	}
	*start_index = index;
	return (flags);
}

int	*transform_argv(char **argv, int *length)
{
	int	*stack_a;
	int	index;

	if (!argv || !length || *length < 1)
		return (NULL);
	if (*length == 1)
	{
		const char *s = argv[0];
		int i = 0;
		int tok_count = 0;

		while (s[i])
		{
			while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
				i++;
			if (!s[i])
				break;
			tok_count++;
			while (s[i] && !(s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
				i++;
		}
		if (tok_count > 1)
		{
			stack_a = malloc(sizeof(int) * tok_count);
			if (!stack_a)
				return (NULL);
			i = 0;
			index = 0;
			while (s[i])
			{
				int start;
				int len;
				char *token;

				while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
					i++;
				if (!s[i])
					break;
				start = i;
				len = 0;
				while (s[i] && !(s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
				{
					i++;
					len++;
				}
				token = malloc(len + 1);
				if (!token)
				{
					free(stack_a);
					return (NULL);
				}
				for (int k = 0; k < len; k++)
					token[k] = s[start + k];
				token[len] = '\0';
				if (stack_a_is_correct(token) || !validate_integer_range(token))
				{
					free(token);
					free(stack_a);
					return (NULL);
				}
				stack_a[index++] = ft_atoi(token);
				free(token);
			}
			*length = tok_count;
			return (stack_a);
		}
	}
	stack_a = malloc(sizeof(int) * *length);
	if (!stack_a)
		return (NULL);
	index = 0;
	while (index < *length)
	{
		if (stack_a_is_correct(argv[index])
			|| !validate_integer_range(argv[index]))
		{
			free(stack_a);
			return (NULL);
		}
		stack_a[index] = ft_atoi(argv[index]);
		index++;
	}
	return (stack_a);
}

void	ft_array_to_list(int *array_a, t_list **stack_a, int length)
{
	t_list	*new_node;
	t_list	**last_node;
	int		index;

	last_node = stack_a;
	while (*last_node)
		last_node = &(*last_node)->next;
	index = 0;
	while (index < length)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			return ;
		new_node->content = array_a[index];
		new_node->next = NULL;
		*last_node = new_node;
		last_node = &new_node->next;
		index++;
	}
}
