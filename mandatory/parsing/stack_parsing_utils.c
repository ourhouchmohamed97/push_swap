/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parsing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:13:14 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/11 11:32:53 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	delete_content(int content)
{
	(void)content;
}

void	handle_error(t_list **lst_tab)
{
	ft_lstclear(lst_tab, delete_content);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	arg_is_valid(char *arg, t_list **lst_tab)
{
	int	i;
	int	found_digit;

	i = 0;
	found_digit = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]))
			found_digit = 1;
		if ((arg[i] >= '0' && arg[i] <= '9') || arg[i] == ' ' || (arg[i] == '+'
				&& (arg[i + 1] >= '0' && arg[i + 1] <= '9')) || (arg[i] == '-'
				&& (arg[i + 1] >= '0' && arg[i + 1] <= '9')))
			i++;
		else
			handle_error(lst_tab);
	}
	if (!found_digit)
		handle_error(lst_tab);
}

int	find_dubble(t_list *lst_tab, int n)
{
	while (lst_tab)
	{
		if (lst_tab->content == n)
			return (1);
		lst_tab = lst_tab->next;
	}
	return (0);
}
