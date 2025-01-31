/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:21:51 by mourhouc          #+#    #+#             */
/*   Updated: 2025/01/31 21:24:48 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

// void free_result(char **result)
// {
//     int i = 0;
//     while (result[i])
//         free(result[i++]);
//     free(result);
// }

// int count_total_numbers(int argc, char *argv[])
// {
//     int count = 0;
//     char **split_numbers;
//     for (int i = 1; i < argc; i++)
//     {
//         split_numbers = ft_split(argv[i], ' ');
//         for (int j = 0; split_numbers[j]; j++)
//             count++;
//         free_result(split_numbers);
//     }
//     return count;
// }

// int main(int argc, char *argv[])
// {
//     t_stack *stack_a;
//     int i, j, total_numbers, index = 0;
//     char **split_numbers;

//     if (argc < 2)
//         return (1);

//     // Step 1: Count total numbers
//     total_numbers = count_total_numbers(argc, argv);
//     if (total_numbers == 0)
//         return (1);

//     // Step 2: Allocate stack_a
//     stack_a = (t_stack *)malloc(sizeof(t_stack));
//     if (!stack_a)
//         return (1);
//     stack_a->len = total_numbers;
//     stack_a->tab = (int *)malloc(sizeof(int) * total_numbers);
//     if (!stack_a->tab)
//     {
//         free(stack_a);
//         return (1);
//     }

//     // Step 3: Fill stack_a->tab
//     i = 1;
//     while (i < argc)
//     {
//         split_numbers = ft_split(argv[i], ' ');
//         j = 0;
//         while (split_numbers[j])
//         {
//             stack_a->tab[index++] = ft_atoi(split_numbers[j]);
//             free(split_numbers[j]);
//             j++;
//         }
//         free(split_numbers);
//         i++;
//     }

//     // Step 4: Print numbers
//     for (i = 0; i < stack_a->len; i++)
//         printf("%d ", stack_a->tab[i]);
//     printf("\n");

//     // Step 5: Free memory
//     free(stack_a->tab);
//     free(stack_a);

//     return (0);
// }


int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_b = NULL;
    if (argc == 1)
        return (0);
    stack_a = ft_parse(argc, argv);

    return (0);
}