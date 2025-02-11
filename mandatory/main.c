/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:21:51 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/11 12:04:20 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_max(t_stack *stack_a)
{
	int	i;
	int	max;

	if (!stack_a || stack_a->len <= 0)
		return (0);
	max = stack_a->tab[0];
	i = 1;
	while (i < stack_a->len)
	{
		if (stack_a->tab[i] > max)
			max = stack_a->tab[i];
		i++;
	}
	return (max);
}

int	find_position(t_stack *stack_a, int n)
{
	int	i;

	i = 0;
	while (i < stack_a->len)
	{
		if (stack_a->tab[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

void	sort_multiple(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 2)
		sort_two(stack_a);
	else if (stack_a->len == 3)
		sort_three(stack_a);
	else if (stack_a->len == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->len == 5)
		sort_five(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	stack_a = ft_parse(argc, argv);
	init_stack_b(stack_a, &stack_b);
	ft_index(stack_a);
	if (stack_a->len > 1 && stack_a->len < 6)
		sort_multiple(stack_a, stack_b);
	else
		ft_sort(stack_a, stack_b);
	while (stack_b->len > 0)
	{
		if (find_position(stack_b, find_max(stack_b)) == 0)
			pa(stack_a, stack_b);
		else if (find_position(stack_b, find_max(stack_b)) <= stack_b->len / 2)
			rb(stack_b);
		else
			rrb(stack_b);
	}
	free_stack(stack_a, stack_b);
	return (0);
}
