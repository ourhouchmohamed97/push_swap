/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:59:15 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/11 11:24:36 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <limits.h>

void	ft_index(t_stack *stack)
{
	int (min_value), (min_index), (i), (j);
	if (!stack || !stack->tab || stack->len == 0)
		return ;
	stack->index = malloc(sizeof(int) * stack->len);
	if (!stack->index)
		return ;
	i = 0;
	while (i < stack->len)
		stack->index[i++] = -1;
	i = 0;
	while (i < stack->len)
	{
		min_value = ((min_index = -1, j = 0), INT_MAX);
		while (j < stack->len)
		{
			if (stack->index[j] == -1 && stack->tab[j] < min_value)
			{
				min_value = stack->tab[j];
				min_index = j;
			}
			j++;
		}
		stack->index[min_index] = i++;
	}
}

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
	int (min_rang), (max_rang);
	min_rang = ((max_rang = stack_a->len * 0.048 + 10), 0);
	while (stack_a->len > 0 && !check_sort(stack_a))
	{
		if (stack_a->index[stack_a->len - 1] < max_rang && ft_compare(stack_a,
				NULL, 'a'))
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
}
