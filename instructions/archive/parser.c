/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/20 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_strategy_flag(char *arg)
{
	if (!arg)
		return (0);
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

static t_strategy	get_strategy(char *flag)
{
	if (ft_strcmp(flag, "--simple") == 0)
		return (SIMPLE);
	if (ft_strcmp(flag, "--medium") == 0)
		return (MEDIUM);
	if (ft_strcmp(flag, "--complex") == 0)
		return (COMPLEX);
	if (ft_strcmp(flag, "--adaptive") == 0)
		return (ADAPTIVE);
	return (ADAPTIVE);
}

t_flags	parse_flags(int argc, char **argv, int *start_index)
{
	t_flags	flags;
	int		i;

	flags.strategy = ADAPTIVE;
	flags.bench = 0;
	i = 1;
	while (i < argc && is_strategy_flag(argv[i]))
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			flags.bench = 1;
		else
			flags.strategy = get_strategy(argv[i]);
		i++;
	}
	*start_index = i;
	return (flags);
}
