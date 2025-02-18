/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:25:05 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/17 11:26:40 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft_utils/libft/libft.h"
# include "../libft_utils/printf/ft_printf.h"
# include "../libft_utils/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				*tab;
	int				len;
	int				*index;
}					t_stack;

typedef struct s_move
{
	char			*move;
	struct s_move	*next;
}					t_move;

// ---------- BONUS -------------

// ************************** CHECKER **************************
void				parse_move(t_stack *a, t_stack *b);
void				do_op(t_stack *a, t_stack *b, char *move);
void				add_list_move(t_move **lst, char *move, t_stack *a,
						t_stack *b);
void				apply_move(t_move **lst, t_stack *a, t_stack *b);

// ************************** CHECKER UTILS **************************
int					is_valid_move(char *move);
void				handle_error_move(t_move **lst, t_stack *a, t_stack *b);
void				clear_content(char *content);
t_stack				*ft_parse(int argc, char **argv);
void				ft_index(t_stack *stack);
int					check_sort(t_stack *stack_a);
void				init_stack_b(t_stack *stack_a, t_stack **stack_b);
void				free_stack(t_stack *stack_a, t_stack *stack_b);

// ************************** CHECKER LIST **************************
t_move				*ft_lstnew_move(char *content);
void				ft_lstadd_back_move(t_move **lst, t_move *new);
void				ft_lstclear_move(t_move **lst, void (*del)(char *));

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

#endif