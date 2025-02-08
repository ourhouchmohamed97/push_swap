/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:24:17 by mourhouc          #+#    #+#             */
/*   Updated: 2025/01/29 17:12:12 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	count;
	int	in_substring;

	count = 0;
	in_substring = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (in_substring)
				count++;
			in_substring = 0;
		}
		else
			in_substring = 1;
		s++;
	}
	if (in_substring)
		count++;
	return (count);
}

static char	*get_substring(const char **s, char c)
{
	const char	*start;
	char		*substring;
	int			length;

	start = *s;
	while (**s && **s != c)
		(*s)++;
	length = *s - start;
	substring = (char *)malloc(length + 1);
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, start, length + 1);
	return (substring);
}

static char	**free_result(char **result)
{
	int	j;

	j = 0;
	if (result)
	{
		while (result[j] != NULL)
		{
			free(result[j]);
			j++;
		}
		free(result);
	}
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	result = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			result[i] = get_substring(&s, c);
			if (!result[i])
				return (free_result(result));
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}
