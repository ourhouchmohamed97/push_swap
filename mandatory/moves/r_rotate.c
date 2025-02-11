/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:36:37 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/11 11:36:53 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stack *stack_a)
{
	int	i;
	int	tmp;
	int	index;

	if (stack_a->len < 2)
		return ;
	tmp = stack_a->tab[stack_a->len - 1];
	index = stack_a->index[stack_a->len - 1];
	i = stack_a->len - 1;
	while (i > 0)
	{
		stack_a->tab[i] = stack_a->tab[i - 1];
		stack_a->index[i] = stack_a->index[i - 1];
		i--;
	}
	stack_a->tab[0] = tmp;
	stack_a->index[0] = index;
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	int	i;
	int	tmp;
	int	index;

	if (stack_b->len < 2)
		return ;
	tmp = stack_b->tab[stack_b->len - 1];
	index = stack_b->index[stack_b->len - 1];
	i = stack_b->len - 1;
	while (i > 0)
	{
		stack_b->tab[i] = stack_b->tab[i - 1];
		stack_b->index[i] = stack_b->index[i - 1];
		i--;
	}
	stack_b->tab[0] = tmp;
	stack_b->index[0] = index;
	ft_printf("rrb\n");
}

void	rra_silent(t_stack *stack_a)
{
	int	i;
	int	tmp;
	int	index;

	if (stack_a->len < 2)
		return ;
	tmp = stack_a->tab[stack_a->len - 1];
	index = stack_a->index[stack_a->len - 1];
	i = stack_a->len - 1;
	while (i > 0)
	{
		stack_a->tab[i] = stack_a->tab[i - 1];
		stack_a->index[i] = stack_a->index[i - 1];
		i--;
	}
	stack_a->tab[0] = tmp;
	stack_a->index[0] = index;
}

void	rrb_silent(t_stack *stack_b)
{
	int	i;
	int	tmp;
	int	index;

	if (stack_b->len < 2)
		return ;
	tmp = stack_b->tab[stack_b->len - 1];
	index = stack_b->index[stack_b->len - 1];
	i = stack_b->len - 1;
	while (i > 0)
	{
		stack_b->tab[i] = stack_b->tab[i - 1];
		stack_b->index[i] = stack_b->index[i - 1];
		i--;
	}
	stack_b->tab[0] = tmp;
	stack_b->index[0] = index;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra_silent(stack_a);
	rrb_silent(stack_b);
	ft_printf("rrr\n");
}
