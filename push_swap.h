/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:09:25 by mourhouc          #+#    #+#             */
/*   Updated: 2025/01/31 21:26:29 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

typedef struct s_stack{
	int	*tab;
	int	len;
}		t_stack;



// ************************** PARSING **************************
void					delete_content(int content);
void					handle_error(t_list **lst_tab);
t_stack					*ft_parse(int argc, char **argv);
void					find_disturb(char *arg, t_list **lst_tab);
int						find_dubble(t_list *lst_tab, int n);
void					add_arg(t_list **lst_tab, char *arg);

#endif