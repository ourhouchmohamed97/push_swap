/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:21:51 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/07 19:30:51 by mourhouc         ###   ########.fr       */
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
    if (stack_a->len == 2)
        sort_two(stack_a);
    else if (stack_a->len == 3)
        sort_three(stack_a);
    else if (stack_a->len == 4)
        sort_four(stack_a, stack_b);
    else if (stack_a->len == 5)
        sort_five(stack_a, stack_b);
    else
        ft_sort(stack_a, stack_b);
    // int i = 0;
    // while (i < stack_a->len)
    // {
    //     printf("%d\n", stack_a->tab[i]);
    //     i++;
    // }
	free_stack(stack_a, stack_b);
    return (0);
}