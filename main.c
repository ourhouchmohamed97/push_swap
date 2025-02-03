/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:21:51 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/03 09:40:59 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>


int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_b = NULL;
    if (argc == 1)
        return (0);
    stack_a = ft_parse(argc, argv);
    int i = 0;
	int tmp;
	while (i < stack_a->len - 1)
	{
		if (stack_a->tab[i] > stack_a->tab[i + 1])
		{
			tmp = stack_a->tab[i + 1];
			stack_a->tab[i + 1] = stack_a->tab[i];
			stack_a->tab[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	while(i < stack_a->len)
	{
        printf("%d - ", stack_a->tab[i]);
		i++;
	}
    return (0);
}