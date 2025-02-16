/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest_silent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:49:29 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/13 09:38:13 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rr_silent(t_stack *stack_a, t_stack *stack_b)
{
	ra_silent(stack_a);
	rb_silent(stack_b);
}

void	rrr_silent(t_stack *stack_a, t_stack *stack_b)
{
	rra_silent(stack_a);
	rrb_silent(stack_b);
	ft_printf("rrr\n");
}
