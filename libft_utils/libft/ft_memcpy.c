/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:05:26 by mourhouc          #+#    #+#             */
/*   Updated: 2024/11/16 21:07:38 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d_data;
	unsigned char	*s_data;
	size_t			i;

	i = 0;
	if (dst == src)
		return (dst);
	d_data = (unsigned char *)dst;
	s_data = (unsigned char *)src;
	while (i < n)
	{
		d_data[i] = s_data[i];
		i++;
	}
	return (dst);
}
