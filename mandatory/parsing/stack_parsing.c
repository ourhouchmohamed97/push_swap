/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:39:24 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/11 11:34:43 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	parse_string(t_list **lst_tab, char *arg)
{
	char	**result;
	int		i;

	i = 0;
	result = ft_split(arg, ' ');
	if (!result)
		handle_error(lst_tab);
	while (result[i])
	{
		add_arg(lst_tab, result[i]);
		i++;
	}
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

void	add_arg(t_list **lst_tab, char *arg)
{
	t_list	*node;
	long	result;

	arg_is_valid(arg, lst_tab);
	if (ft_strchr(arg, ' '))
		parse_string(lst_tab, arg);
	else
	{
		result = ft_atoi(arg);
		if (result == 2147483648 || find_dubble(*lst_tab, result))
			handle_error(lst_tab);
		node = ft_lstnew((int)result);
		if (!node)
			handle_error(lst_tab);
		ft_lstadd_back(lst_tab, node);
	}
}

t_stack	*copy_lst_to_tab(t_list **lst_tab, t_stack *result)
{
	int		len_tab;
	t_list	*temp;

	len_tab = 0;
	temp = *lst_tab;
	while (temp)
	{
		len_tab++;
		temp = temp->next;
	}
	result->tab = malloc((len_tab) * sizeof(int));
	if (!result->tab)
		handle_error(lst_tab);
	len_tab = 0;
	temp = *lst_tab;
	while (temp)
	{
		result->tab[len_tab++] = temp->content;
		temp = temp->next;
	}
	ft_lstclear(lst_tab, delete_content);
	result->len = len_tab;
	return (result);
}

t_stack	*ft_parse(int argc, char **argv)
{
	t_list	*lst_tab;
	t_stack	*result;
	int		i;

	lst_tab = NULL;
	i = 1;
	while (i < argc)
	{
		add_arg(&lst_tab, argv[i++]);
	}
	result = malloc(sizeof(t_stack));
	if (!result)
		handle_error(&lst_tab);
	return (copy_lst_to_tab(&lst_tab, result));
}
