/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:21:51 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/04 13:11:41 by mourhouc         ###   ########.fr       */
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
    init_stack_b(stack_a, &stack_b);
    stack_b->tab[0] = 5;
    stack_b->tab[1] = 1;
    stack_b->tab[2] = 3;
    stack_b->len = 3;
    pa(stack_a, stack_b);
    // sa(stack_a);
    ft_printf("stack a\n");
    int i = 0;
    while (i < stack_a->len)
    {
        ft_printf("%d \n", stack_a->tab[i]);
        i++;
    }
    ft_printf("stack b\n");
    i = 0;
    while (i < stack_b->len)
    {
        ft_printf("%d \n", stack_b->tab[i]);
        i++;
    }
	// free_stack(stack_a, stack_b);
    return (0);
}