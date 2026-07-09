/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:10:21 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 13:10:23 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stddef.h>

size_t  ft_strlen(const char *s)
{
  size_t  num;
  size_t  i;

  num = 0;
  i = 0;
  while (s[i] != '\0')
  {
    num++;
    i++;
  }
  return (num);
}

static long  ft_putnum(const char *str, long num, int i, int neg)
{
  while (str[i] >= '0' && str[i] <= '9')
  {
    num = (str[i] - 48) + (num * 10);
    i++;
  }
  if (neg == 1)
    num = num * -1;
  return (num);
}

int ft_atoi(const char *nptr)
{
  int i;
  long num;
  int neg;

  i = 0;
  num = 0;
  neg = 0;
  while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
    i++;
  if (nptr[i] == '-')
  {
    neg = 1;
    i++;
  }
  else if (nptr[i] == '+')
    i++;
  if (nptr[i] < '0' || nptr[i] > '9')
    return (0);
  num = ft_putnum(nptr, num, i, neg);
  return ((int)num);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	c;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	if (num < 10)
	{
		c = num + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(num / 10, fd);
		c = (num % 10) + '0';
		write(fd, &c, 1);
	}
}

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
}
