/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parsing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:13:14 by mourhouc          #+#    #+#             */
/*   Updated: 2025/01/31 21:27:04 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	delete_content(int content)
{
	(void)content;
}

void	handle_error(t_list **lst_tab)
{
	ft_lstclear(lst_tab, &delete_content);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	find_disturb(char *arg,  t_list **lst_tab)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if ((arg[i] >= '0' && arg[i] <= '9') || arg[i] == ' ' || arg[i] == '+'
			|| arg[i] == '-')
			i++;
		else
			handle_error(lst_tab);
	}
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