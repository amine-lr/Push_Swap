/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: GitHub Copilot <copilot@local>              +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 00:00:00 by copilot           #+#    #+#             */
/*   Updated: 2026/08/18 00:00:00 by copilot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_tokens(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
			i++;
		if (!s[i])
			break ;
		count++;
		while (s[i] && !(s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
			i++;
	}
	return (count);
}

static int	get_token_value(const char *s, int start, int len, int *val)
{
	char	*token;
	int		k;

	token = malloc(len + 1);
	if (!token)
		return (0);
	k = 0;
	while (k < len)
	{
		token[k] = s[start + k];
		k++;
	}
	token[len] = '\0';
	if (stack_a_is_correct(token) || !validate_integer_range(token))
	{
		free(token);
		return (0);
	}
	*val = ft_atoi(token);
	free(token);
	return (1);
}

static int	ft_token_len(const char *s)
{
	int	len;

	len = 0;
	while (s[len] && !(s[len] == ' ' || (s[len] >= 9 && s[len] <= 13)))
		len++;
	return (len);
}

static int	*extract_numbers(const char *s, int count)
{
	int	*arr;
	int	i;
	int	idx;
	int	val;

	arr = malloc(sizeof(int) * count);
	if (!arr)
		return (NULL);
	i = 0;
	idx = 0;
	while (s[i])
	{
		while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
			i++;
		if (!s[i])
			break ;
		if (!get_token_value(s, i, ft_token_len(&s[i]), &val))
			return (free(arr), NULL);
		arr[idx++] = val;
		i += ft_token_len(&s[i]);
	}
	return (arr);
}

int	*parse_tokens(const char *s, int *out_len)
{
	int	count;
	int	*res;

	if (!s || !out_len)
		return (NULL);
	count = count_tokens(s);
	if (count <= 1)
		return (NULL);
	res = extract_numbers(s, count);
	if (!res)
		return (NULL);
	*out_len = count;
	return (res);
}
