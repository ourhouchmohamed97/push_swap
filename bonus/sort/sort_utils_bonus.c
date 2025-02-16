/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:31:27 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/15 12:18:48 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	exit(1);
}

void	init_stack_b(t_stack *stack_a, t_stack **stack_b)
{
	*stack_b = malloc(sizeof(t_stack));
	if (!(*stack_b))
		handle_error_stack(stack_a, *stack_b);
	(*stack_b)->tab = malloc(sizeof(int) * stack_a->len);
	(*stack_b)->index = malloc(sizeof(int) * stack_a->len);
	if (!(*stack_b)->tab || !(*stack_b)->index)
		handle_error_stack(stack_a, (*stack_b));
	(*stack_b)->len = 0;
}

void	free_stack(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->tab);
	free(stack_b->tab);
	free(stack_a->index);
	free(stack_b->index);
	free(stack_a);
	free(stack_b);
}

int	check_sort(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a->len - 1)
	{
		if (stack_a->index[i] != stack_a->index[i + 1] - 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_rev_sort(t_stack *stack_a)
{
	int	i;

	i = 1;
	while (i < stack_a->len)
	{
		if (stack_a->tab[i - 1] < stack_a->tab[i])
			return (0);
		i++;
	}
	return (1);
}
