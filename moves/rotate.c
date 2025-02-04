/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:16:56 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/04 16:09:27 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *stack_a)
{
	int	i;
	int	tmp;

	if (stack_a->len < 2)
		return ;
	tmp = stack_a->tab[0];
	i = 0;
	while (i < stack_a->len - 1)
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		i++;
	}
	stack_a->tab[i] = tmp;
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	int	i;
	int	tmp;

	if (stack_b->len < 2)
		return ;
	tmp = stack_b->tab[0];
	i = 0;
	while (i < stack_b->len - 1)
	{
		stack_b->tab[i] = stack_b->tab[i + 1];
		i++;
	}
	stack_b->tab[i] = tmp;
	ft_printf("rb\n");
}

void	ra_silent(t_stack *stack_a)
{
	int	i;
	int	tmp;

	if (stack_a->len < 2)
		return ;
	tmp = stack_a->tab[0];
	i = 0;
	while (i < stack_a->len - 1)
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		i++;
	}
	stack_a->tab[i] = tmp;
}

void	rb_silent(t_stack *stack_b)
{
	int	i;
	int	tmp;

	if (stack_b->len < 2)
		return ;
	tmp = stack_b->tab[0];
	i = 0;
	while (i < stack_b->len - 1)
	{
		stack_b->tab[i] = stack_b->tab[i + 1];
		i++;
	}
	stack_b->tab[i] = tmp;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra_silent(stack_a);
	rb_silent(stack_b);
	ft_printf("rr\n");
}