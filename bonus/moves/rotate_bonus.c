/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:16:56 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/11 11:36:07 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stack *stack_a)
{
	int	i;
	int	tmp;
	int	index;

	if (stack_a->len < 2)
		return ;
	tmp = stack_a->tab[0];
	index = stack_a->index[0];
	i = 0;
	while (i < stack_a->len - 1)
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		stack_a->index[i] = stack_a->index[i + 1];
		i++;
	}
	stack_a->tab[i] = tmp;
	stack_a->index[i] = index;
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	int	i;
	int	tmp;
	int	index;

	if (stack_b->len < 2)
		return ;
	tmp = stack_b->tab[0];
	index = stack_b->index[0];
	i = 0;
	while (i < stack_b->len - 1)
	{
		stack_b->tab[i] = stack_b->tab[i + 1];
		stack_b->index[i] = stack_b->index[i + 1];
		i++;
	}
	stack_b->tab[i] = tmp;
	stack_b->index[i] = index;
	ft_printf("rb\n");
}

void	ra_silent(t_stack *stack_a)
{
	int	i;
	int	tmp;
	int	index;

	if (stack_a->len < 2)
		return ;
	tmp = stack_a->tab[0];
	index = stack_a->index[0];
	i = 0;
	while (i < stack_a->len - 1)
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		stack_a->index[i] = stack_a->index[i + 1];
		i++;
	}
	stack_a->tab[i] = tmp;
	stack_a->index[i] = index;
}

void	rb_silent(t_stack *stack_b)
{
	int	i;
	int	tmp;
	int	index;

	if (stack_b->len < 2)
		return ;
	tmp = stack_b->tab[0];
	index = stack_b->index[0];
	i = 0;
	while (i < stack_b->len - 1)
	{
		stack_b->tab[i] = stack_b->tab[i + 1];
		stack_b->index[i] = stack_b->index[i + 1];
		i++;
	}
	stack_b->tab[i] = tmp;
	stack_b->index[i] = index;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra_silent(stack_a);
	rb_silent(stack_b);
	ft_printf("rr\n");
}
