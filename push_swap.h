/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:09:25 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/04 11:57:02 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int	*tab;
	int	len;
}		t_stack;



// ************************** PARSING **************************
void					delete_content(int content);
void					handle_error(t_list **lst_tab);
t_stack					*ft_parse(int argc, char **argv);
void					arg_is_valid(char *arg, t_list **lst_tab);
int						find_dubble(t_list *lst_tab, int n);
void					add_arg(t_list **lst_tab, char *arg);

// ************************** UTILS **************************
void					init_stack_b(t_stack *stack_a, t_stack **stack_b);
void					handle_error_stack(t_stack *stack_a, t_stack *stack_b);
void					free_stack(t_stack *stack_a, t_stack *stack_b);
int						check_sort(t_stack *stack_a);
int						check_rev_sort(t_stack *stack_a);

// ************************** MOVES **************************
void					sa(t_stack *stack_a);
void					sb(t_stack *stack_b);
void					ss(t_stack *stack_a, t_stack *stack_b);

#endif