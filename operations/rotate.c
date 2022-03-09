/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:28:33 by emcariot          #+#    #+#             */
/*   Updated: 2022/03/08 12:50:11 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate(t_list **piles)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*piles) < 2)
		return (-1);
	head = *piles;
	tail = ft_lstlast(head);
	*piles = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	rotate_a(t_list **pile_a)
{
	if (rotate(pile_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rotate_b(t_list **pile_b)
{
	if (rotate(pile_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rotate_rotate(t_list **pile_a, t_list **pile_b)
{
	if ((ft_lstsize(*pile_a) < 2) || (ft_lstsize(*pile_b) < 2))
		return (-1);
	rotate(pile_a);
	rotate(pile_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
