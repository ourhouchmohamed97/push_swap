/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:58:07 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/17 09:25:43 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup_gnl(char *str)
{
	char	*dest;
	int		i;

	if (!str)
		return (NULL);
	dest = malloc(ft_strlen_gnl(str) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	char	*start;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup_gnl(s2));
	if (!s2)
		return (ft_strdup_gnl(s1));
	dest = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!dest)
		return (NULL);
	start = dest;
	while (*s1)
		*dest++ = *s1++;
	while (*s2)
		*dest++ = *s2++;
	*dest = '\0';
	return (start);
}

char	*ft_strchr_gnl(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str != (char)c && *str)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}
