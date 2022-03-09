/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:30:37 by emcariot          #+#    #+#             */
/*   Updated: 2022/03/09 15:15:57 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;

}				t_list;

//OPERATIONS
int		rotate_a(t_list **pile_a);
int		rotate_b(t_list **pile_b);
int		rotate_rotate(t_list **pile_a, t_list **pile_b);
int		swap_a(t_list **pile_a);
int		swap_b(t_list **pile_b);
int		swap_swap(t_list **pile_a, t_list **pile_b);
int		reverse_rotate_a(t_list **pile_a);
int		reverse_rotate_b(t_list **pile_b);
int		reverse_rotate_rotate(t_list **pile_a, t_list **pile_b);
int		push_a(t_list **pile_a, t_list **pile_b);
int		push_b(t_list **pile_a, t_list **pile_b);

//ALGO
int		already_sorted(t_list **piles);
void	sort_5_and_less(t_list **pile_a, t_list **pile_b);
void	recap_sort(t_list **pile_a, t_list **pile_b);
int		get_bytes(t_list **piles);
void	radix_sort(t_list **pile_a, t_list **pile_b);

//UTILS
t_list	*ft_lstnew(int value);
void	ft_lstadd_front(t_list **stack, t_list *new);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_back(t_list **stack, t_list *new);
int		ft_lstsize(t_list *head);
long	ft_atoi(char *str);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
int		get_distance(t_list **stack, int index);
void	index_stack(t_list **stack);

//PARSING
void	check_args(int ac, char **av);

//FREE
void	free_stack(t_list **piles);
void	ft_free(char **str);

//ERROR
void	display_error(char *str);
void	ft_error_tab(char **str, char *s);

#endif