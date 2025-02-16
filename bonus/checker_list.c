/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:04:53 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/16 19:00:15 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_move	*ft_lstnew_move(char *content)
{
	t_move	*new;

	new = (t_move *)malloc(sizeof(t_move));
	if (!new)
		return (NULL);
	new->move = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_move(t_move **lst, t_move *new)
{
	t_move	*last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	ft_lstclear_move(t_move **lst, void (*del)(char *))
{
	t_move	*current;
	t_move	*next_node;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next_node = current->next;
		del(current->move);
		free(current);
		current = next_node;
	}
	*lst = NULL;
}
