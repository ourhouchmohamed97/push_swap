/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:19:36 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/05 19:18:12 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		sa(stack_a);
		ra(stack_a);
	}
	else
		sa(stack_a);
}


void	sort_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (check_sort)
		return ;
	
}