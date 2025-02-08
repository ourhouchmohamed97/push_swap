/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:53:59 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/08 12:03:18 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stack *stack_a)
{
	int	tmp;
	if (stack_a->len < 2)
		return ;
	tmp = stack_a->tab[0];
	stack_a->tab[0] = stack_a->tab[1];
	stack_a->tab[1] = tmp;
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	int	tmp;
	if (stack_b->len < 2)
		return ;
	tmp = stack_b->tab[0];
	stack_b->tab[0] = stack_b->tab[1];
	stack_b->tab[1] = tmp;
	ft_printf("sb\n");
}
void	sa_silent(t_stack *stack_a)
{
	int	tmp;
	if (stack_a->len < 2)
		return ;
	tmp = stack_a->tab[0];
	stack_a->tab[0] = stack_a->tab[1];
	stack_a->tab[1] = tmp;
}

void	sb_silent(t_stack *stack_b)
{
	int	tmp;
	if (stack_b->len < 2)
		return ;
	tmp = stack_b->tab[0];
	stack_b->tab[0] = stack_b->tab[1];
	stack_b->tab[1] = tmp;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa_silent(stack_a);
	sb_silent(stack_b);
	ft_printf("ss\n");
}