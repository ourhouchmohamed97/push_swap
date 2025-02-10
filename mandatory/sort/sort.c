/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:19:36 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/09 16:15:18 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int		find_min(t_stack *stack)
{
	int i;
	int min;

	min = stack->tab[0];
	i = 1;
	while (i < stack->len)
	{
		if(stack->tab[i] < min)
			min = stack->tab[i];
		i++;
	}
	return (min);
}

void	sort_two(t_stack *stack_a)
{
	if (!check_sort(stack_a))
		sa(stack_a);
}

void	sort_three(t_stack *stack_a)
{
	if (check_sort(stack_a))
		return ;
	if (check_rev_sort(stack_a))
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (stack_a->tab[0] > stack_a->tab[1] && stack_a->tab[0] > stack_a->tab[2])
		ra(stack_a);
	else if (stack_a->tab[0] < stack_a->tab[1] && stack_a->tab[0] > stack_a->tab[2])
		rra(stack_a);
	else if (stack_a->tab[0] < stack_a->tab[1] && stack_a->tab[1] > stack_a->tab[2])
	{
		rra(stack_a);
		sa(stack_a);
	}
	else
		sa(stack_a);
}


void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int len;

	if (check_sort(stack_a))
		return ;
	min = find_min(stack_a);
	len = stack_a->len;
	while (stack_a->tab[0] != min && stack_a->tab[len - 1] != min)
		ra(stack_a);
	if (stack_a->tab[len - 1] == min)
		rra(stack_a);
	if (check_sort(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	len;

	if (check_sort(stack_a))
		return ;
	min = find_min(stack_a);
	len = stack_a->len;
	while (stack_a->tab[0] != min && stack_a->tab[len - 1] != min && stack_a->tab[len - 2] != min)
		ra(stack_a);
	if(stack_a->tab[len - 1] == min)
		rra(stack_a);
	else if (stack_a->tab[len - 2] == min)
	{
		rra(stack_a);
		rra(stack_a);
	}
	if (check_sort(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}