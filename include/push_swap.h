/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:09:25 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/17 09:15:00 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft_utils/libft/libft.h"
# include "../libft_utils/printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				*tab;
	int				len;
	int				*index;
}					t_stack;

// ---------- MANDATORY -------------

// ************************** PARSING **************************
void				delete_content(int content);
void				handle_error(t_list **lst_tab);
t_stack				*ft_parse(int argc, char **argv);
void				arg_is_valid(char *arg, t_list **lst_tab);
int					find_dubble(t_list *lst_tab, int n);
void				add_arg(t_list **lst_tab, char *arg);

// ************************** UTILS **************************
void				init_stack_b(t_stack *stack_a, t_stack **stack_b);
void				handle_error_stack(t_stack *stack_a, t_stack *stack_b);
void				free_stack(t_stack *stack_a, t_stack *stack_b);
int					check_sort(t_stack *stack_a);
int					check_rev_sort(t_stack *stack_a);

// ************************** MOVES **************************
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);

// ************************** MOVES SILENT **************************
void				sa_silent(t_stack *stack_a);
void				sb_silent(t_stack *stack_b);
void				ss_silent(t_stack *stack_a, t_stack *stack_b);
void				pa_silent(t_stack *stack_a, t_stack *stack_b);
void				pb_silent(t_stack *stack_a, t_stack *stack_b);
void				ra_silent(t_stack *stack_a);
void				rb_silent(t_stack *stack_b);
void				rr_silent(t_stack *stack_a, t_stack *stack_b);
void				rra_silent(t_stack *stack_a);
void				rrb_silent(t_stack *stack_b);
void				rrr_silent(t_stack *stack_a, t_stack *stack_b);

// ************************** SORT **************************
void				sort_two(t_stack *stack_a);
void				sort_three(t_stack *stack_a);
void				sort_four(t_stack *stack_a, t_stack *stack_b);
void				sort_five(t_stack *stack_a, t_stack *stack_b);

// ************************** SORT UTILS **************************
int					find_min(t_stack *stack);
void				ft_index(t_stack *stack);
int					complete(t_stack *stack_a, t_stack *stack_b, char c);
void				ft_sort(t_stack *stack_a, t_stack *stack_b);
int					find_position(t_stack *stack_a, int n);
int					find_max(t_stack *stack_a);


#endif