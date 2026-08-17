/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_strategy(t_flags flags, t_sort_data *data)
{
	if (flags.strategy == SIMPLE)
		simple_sort(data->stack_a, data->stack_b, data->operations);
	else if (flags.strategy == MEDIUM)
		medium_sort(data->stack_a, data->stack_b, data->operations);
	else if (flags.strategy == COMPLEX)
		complex_sort(data);
	else
		adaptive_sort(data);
}
