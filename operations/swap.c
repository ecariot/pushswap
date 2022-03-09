/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:39:46 by emmacariot        #+#    #+#             */
/*   Updated: 2022/03/08 12:54:23 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap(t_list **piles)
{
	t_list	*head;
	t_list	*next;
	int		tmp_value;
	int		tmp_index;

	if (ft_lstsize(*piles) < 2)
		return (-1);
	head = *piles;
	next = head->next;
	if (!head && !next)
		ft_putendl_fd("Error", 1);
	tmp_value = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_value;
	next->index = tmp_index;
	return (0);
}

int	swap_a(t_list **pile_a)
{
	if (swap(pile_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	swap_b(t_list **pile_b)
{
	if (swap(pile_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	swap_swap(t_list **pile_a, t_list **pile_b)
{
	if ((ft_lstsize(*pile_a) < 2) || ft_lstsize(*pile_b) < 2)
		return (-1);
	swap(pile_a);
	swap(pile_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
