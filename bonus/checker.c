/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:46:35 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/13 09:54:34 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	add_list_move(t_move **lst, char *move, t_stack *a, t_stack *b)
{
	t_move	*node; 

	node = NULL;
	node = ft_lstnew_move(move);
	if (!node)
		handle_error_move(lst, a, b);
	ft_lstadd_back_move(lst, node);
}

void	do_op(t_stack *a, t_stack *b, char *move)
{
	if (ft_strncmp(move, "rra", 3) == 0)
		rra_silent(a);
	else if (ft_strncmp(move, "rrb", 3) == 0)
		rrb_silent(a);
	else if (ft_strncmp(move, "rrr", 3) == 0)
		rrr_silent(a, b);
	else if (ft_strncmp(move, "ra", 2) == 0)
		ra_silent(a);
	else if (ft_strncmp(move, "rb", 2) == 0)
		rb_silent(b);
	else if (ft_strncmp(move, "rr", 2) == 0)
		rr_silent(a, b);
	else if (ft_strncmp(move, "pa", 2) == 0)
		pa_silent(a, b);
	else if (ft_strncmp(move, "pb", 2) == 0)
		pb_silent(a, b);
	else if (ft_strncmp(move, "sa", 2) == 0)
		sa_silent(a);
	else if (ft_strncmp(move, "sb", 2) == 0)
		sb_silent(b);
	else if (ft_strncmp(move, "ss", 2) == 0)
		ss_silent(a, b);
}

void	apply_move(t_move **lst, t_stack *a, t_stack *b)
{
	t_move	*tmp;

	tmp = *lst;
	while (tmp)
	{
		do_op(a, b, tmp->move);
		tmp = tmp->next;
	}
	if (check_sort(a) && b->len == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear_move(lst, &clear_content);
	free_stack(a, b);
}

void	parse_move(t_stack *a, t_stack *b)
{
	t_move		*lst;
	char		*move;

	lst = NULL;
	move = get_next_line(0);
	while (move)
	{
		add_list_move(&lst, move, a, b);
		if (!is_valid_move(move))
			handle_error_move(&lst, a, b);
		move = get_next_line(0);
	}
	apply_move(&lst, a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	stack_a = ft_parse(argc, argv);
	init_stack_b(stack_a, &stack_b);
	ft_index(stack_a);
	parse_move(stack_a, stack_b);
	return (0);
}
