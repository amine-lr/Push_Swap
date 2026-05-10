/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:27:05 by mlarioui          #+#    #+#             */
/*   Updated: 2024/10/05 17:05:56 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_pointer(va_list args)
{
	void	*ptr;
	int		count;

	count = 0;
	ptr = va_arg(args, void *);
	if (ptr == NULL)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += puthexnbr((size_t)ptr, 0, 'x');
	}
	return (count);
}

int	ft_format(va_list args, const char *s)
{
	int	count;

	count = 0;
	if (*s == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*s == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (*s == 'd' || *s == 'i')
		count += ft_putnbr(va_arg(args, int), 0);
	else if (*s == 'u')
		count += ft_putnbr_pos(va_arg(args, unsigned int), 0);
	else if (*s == 'x')
		count += puthexnbr(va_arg(args, unsigned int), 0, 'x');
	else if (*s == 'X')
		count += puthexnbr(va_arg(args, unsigned int), 0, 'X');
	else if (*s == 'p')
		count += format_pointer(args);
	else if (*s == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i +1])
		{
			i++;
			count += ft_format(args, &str[i]);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
