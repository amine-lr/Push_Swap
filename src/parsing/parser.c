#include "../../include/push_swap.h"

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
	int		i;

	flags.strategy = ADAPTIVE;
	flags.bench = 0;
	i = 1;
	while (i < argc && is_known_flag(argv[i]))
	{
		apply_flag(&flags, argv[i]);
		i++;
	}
	*start_index = i;
	return (flags);
}
