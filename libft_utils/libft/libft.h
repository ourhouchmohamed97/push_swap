/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:23:24 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/13 09:39:05 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
void				*ft_memcpy(void *dst, const void *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
long				ft_atoi(const char *str);
char				*ft_strdup(const char *s1);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
int					ft_isdigit(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

// ************************** LIST **************************

t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(int));

#endif
