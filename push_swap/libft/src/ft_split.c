/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:13:59 by molariou          #+#    #+#             */
/*   Updated: 2026/04/25 13:13:59 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_wordcount_allocat(const char *s, char c)
{
	int		count;
	int		in_word;
	char	**result;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	result = (char **)malloc((count +1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (result);
}

static char	*ft_word_dup(const char *s, int start, int end)
{
	char	*word;
	int		i;
	size_t	len;

	i = 0;
	len = end - start;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	ft_free(char **result, int words)
{
	int	i;

	i = 0;
	while (i < words)
		free(result[i++]);
	free(result);
}

static int	ft_fill_result(char **result, const char *s, char c)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			result[j++] = ft_word_dup(s, start, i);
			if (!result[j - 1])
			{
				ft_free(result, j - 1);
				return (0);
			}
		}
	}
	result[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = ft_wordcount_allocat(s, c);
	if (!result)
		return (NULL);
	if (!ft_fill_result(result, s, c))
		return (NULL);
	return (result);
}
/*
int main(void)
{
    char **result = ft_split(NULL, ' ');
    int i = 0;

    if (!result)
	{
        printf("can't split NULL");
		return (0);
	}
    while (result[i])
    {
        printf("%s\n", result[i]);
        free(result[i++]);
    }
    free(result);

    return 0;
}*/