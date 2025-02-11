/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:53:59 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/11 11:33:34 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stack *stack_a)
{
	int	tmp;
	int	index;

	if (stack_a->len < 2)
		return ;
	tmp = stack_a->tab[0];
	index = stack_a->index[0];
	stack_a->tab[0] = stack_a->tab[1];
	stack_a->index[0] = stack_a->index[1];
	stack_a->tab[1] = tmp;
	stack_a->index[1] = index;
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	int	tmp;
	int	index;

	if (stack_b->len < 2)
		return ;
	tmp = stack_b->tab[0];
	index = stack_b->index[0];
	stack_b->tab[0] = stack_b->tab[1];
	stack_b->index[0] = stack_b->index[1];
	stack_b->tab[1] = tmp;
	stack_b->index[1] = index;
	ft_printf("sb\n");
}

void	sa_silent(t_stack *stack_a)
{
	int	tmp;
	int	index;

	if (stack_a->len < 2)
		return ;
	tmp = stack_a->tab[0];
	index = stack_a->index[0];
	stack_a->tab[0] = stack_a->tab[1];
	stack_a->index[0] = stack_a->index[1];
	stack_a->tab[1] = tmp;
	stack_a->index[1] = index;
}

void	sb_silent(t_stack *stack_b)
{
	int	tmp;
	int	index;

	if (stack_b->len < 2)
		return ;
	tmp = stack_b->tab[0];
	index = stack_b->index[0];
	stack_b->tab[0] = stack_b->tab[1];
	stack_b->index[0] = stack_b->index[1];
	stack_b->tab[1] = tmp;
	stack_b->index[1] = index;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa_silent(stack_a);
	sb_silent(stack_b);
	ft_printf("ss\n");
}
