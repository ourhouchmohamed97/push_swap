/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:46:54 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/06 13:35:18 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	i = stack_a->len;
	if (stack_a->len == 0)
		return ;
	while(i > 0)
	{
		stack_a->tab[i] = stack_a->tab[i - 1];
		i--;
	}
	stack_a->tab[0] = stack_b->tab[0];
	stack_a->len++;
	stack_b->len--;
	while (i < stack_b->len)
	{
		stack_b->tab[i] = stack_b->tab[i + 1];
		i++;
	}
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	i = stack_b->len;
	if (stack_a->len == 0)
		return ;
	while(i > 0)
	{
		stack_b->tab[i] = stack_b->tab[i - 1];
		i--;
	}
	stack_b->tab[0] = stack_a->tab[0];
	stack_b->len++;
	stack_a->len--;	
	while (i < stack_a->len)
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		i++;
	}
	ft_printf("pb\n");
} 