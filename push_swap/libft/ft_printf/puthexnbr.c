/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthexnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:37:38 by mlarioui          #+#    #+#             */
/*   Updated: 2024/10/05 16:53:22 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthexnbr(size_t arg, int count, char n_type)
{
	if (arg >= 16)
	{
		count = puthexnbr(arg / 16, count, n_type);
	}
	if ((n_type == 'x'))
		count += ft_putchar("0123456789abcdef"[arg % 16]);
	if (n_type == 'X')
		count += ft_putchar("0123456789ABCDEF"[arg % 16]);
	return (count);
}
