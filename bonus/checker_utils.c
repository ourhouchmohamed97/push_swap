/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:03:36 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/11 13:29:20 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_valid_move(char *move)
{
	size_t	len;

	len = ft_strlen(move);
	return ((len == 3 && (!ft_strncmp(move, "ra\n", 3)
				|| !ft_strncmp(move, "rb\n", 3) || !ft_strncmp(move,
					"rr\n", 3) || !ft_strncmp(move, "sa\n", 3)
				|| !ft_strncmp(move, "sb\n", 3) || !ft_strncmp(move,
					"ss\n", 3) || !ft_strncmp(move, "pb\n", 3)
				|| !ft_strncmp(move, "pa\n", 3))) || (len == 4
			&& (!ft_strncmp(move, "rra\n", 4) || !ft_strncmp(move,
					"rrb\n", 4) || !ft_strncmp(move, "rrr\n", 4))));
}
void	clear_content(char *content)
{
	free(content);
}

void	handle_error_move(t_move **lst, t_stack *a, t_stack *b)
{
	ft_lstclear_move(lst, &clear_content);
	free_stack(a, b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}