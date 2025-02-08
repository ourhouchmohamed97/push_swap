/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:31:27 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/08 11:22:01 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		free(stack_a->tab);
		free(stack_a);
	}
	if (stack_b)
	{
		free(stack_b->tab);
		free(stack_b);
	}
	exit(EXIT_FAILURE);
}

void	init_stack_b(t_stack *stack_a, t_stack **stack_b)
{
	*stack_b = malloc(sizeof(t_stack));
	if (!(*stack_b))
		handle_error_stack(stack_a, *stack_b);
	(*stack_b)->tab = malloc(sizeof(int) * stack_a->len);
	if (!(*stack_b)->tab)
		handle_error_stack(stack_a, (*stack_b));
	(*stack_b)->len = 0;
}

void	free_stack(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->tab);
	free(stack_b->tab);
	free(stack_a);
	free(stack_b);
}

int	check_sort(t_stack *stack_a)
{
	int	i;

	i = 1;
	while(i < stack_a->len)
	{
		if(stack_a->tab[i - 1] > stack_a->tab[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_rev_sort(t_stack *stack_a)
{
	int i;

	i = 1;
	while (i < stack_a->len)
	{
		if (stack_a->tab[i - 1] < stack_a->tab[i])
			return (0);
		i++;
	}
	return (1);
}