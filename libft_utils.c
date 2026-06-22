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

#include "push_swap.h"
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

static int  ft_putnum(const char *str, int num, int i, int neg)
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
  int num;
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
  return (num);
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
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		c = (n % 10) + '0';
		write(fd, &c, 1);
	}
}
