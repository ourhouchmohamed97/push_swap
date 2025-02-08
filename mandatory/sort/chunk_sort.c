/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:59:15 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/08 12:04:07 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void	ft_index(t_stack *stack)
{
    int i, j;
    int min_value;
    int min_index;

    if (!stack || !stack->tab || stack->len == 0)
        return;
	i = 0;
    while (i < stack->len)
    {
        stack->index[i] = -1;
		i++;
    }
	i = 0;
    while (i < stack->len)
    {
        min_value = INT_MAX;
        min_index = -1;
		j = 0;
        while (j < stack->len)
        {
            if (stack->index[j] == -1 && stack->tab[j] < min_value)
            {
                min_value = stack->tab[j];
                min_index = j;
            }
			j++;
        }
        stack->index[min_index] = i;
		i++;
    }
}

// // Function to print the values and their assigned indices
// void print_stack(t_stack *stack)
// {
//     for (int i = 0; i < stack->len; i++)
//     {
//         printf("Value: %d, Index: %d\n", stack->tab[i], stack->index[i]);
//     }
// }

// int main()
// {
//     int values[] = {50, 20, 40, 10, 30};
//     t_stack stack;
//     stack.len = sizeof(values) / sizeof(values[0]);

//     // Allocate memory for tab and index arrays
//     stack.tab = malloc(stack.len * sizeof(int));
//     stack.index = malloc(stack.len * sizeof(int));

//     if (!stack.tab || !stack.index)
//     {
//         printf("Memory allocation failed\n");
//         return 1;
//     }

//     // Copy values into the stack's tab array
//     for (int i = 0; i < stack.len; i++)
//     {
//         stack.tab[i] = values[i];
//     }
//     ft_index(&stack);

//     // Print the stack values with their assigned indices
//     printf("\nAfter assigning indices:\n");
//     print_stack(&stack);

//     // Free allocated memory
//     free(stack.tab);
//     free(stack.index);

//     return 0;
// }

int	ft_compare(t_stack *stack_a, t_stack *stack_b, char c)
{
	if (c == 'a' && stack_a->len > 1
		&& stack_a->index[0] > stack_a->index[stack_a->len - 1])
		return (1);
	if (c == 'b')
	{
		if (ft_compare(stack_a, NULL, 'a'))
			rra(stack_a);
		pb(stack_a, stack_b);
		if (stack_b->len > 1 && stack_b->index[0] < stack_b->index[1])
			sb(stack_b);
	}
	return (0);
}


void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_rang;
	int	max_rang;

	min_rang = 0;
	max_rang = stack_a->len * 0.048 + 10;
	while (stack_a && !check_sort(stack_a))
		if (stack_a->index[stack_a->len - 1] < max_rang && ft_compare(stack_a, NULL, 'a'))
			rra(stack_a);
	else if (stack_a->index[0] > max_rang)
		ra(stack_a);
	else if (stack_a->index[0] < min_rang)
	{
		pb(stack_a, stack_b);
		if (stack_a->index[0] > max_rang)
			rr(stack_a, stack_b);
		else
			rb(stack_b);
		min_rang = ((max_rang++), min_rang + 1);
	}
	else
	{
		ft_compare(stack_a, stack_b, 'b');
		max_rang++;
		min_rang++;
	}
}
