/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:29:06 by mlarioui          #+#    #+#             */
/*   Updated: 2024/10/05 16:57:06 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	format_pointer(va_list args);
int	ft_format(va_list args, const char *s);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n, int count);
int	ft_putnbr_pos(unsigned int n, int count);
int	puthexnbr(size_t arg, int count, char n_type);

#endif
