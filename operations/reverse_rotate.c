/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:28:41 by emmacariot        #+#    #+#             */
/*   Updated: 2022/03/08 12:46:27 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	reverse_rotate(t_list **piles)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*piles) < 2)
		return (-1);
	head = *piles;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *piles;
	*piles = tail;
	return (0);
}

int	reverse_rotate_a(t_list **pile_a)
{
	if (reverse_rotate(pile_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	reverse_rotate_b(t_list **pile_b)
{
	if (reverse_rotate(pile_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	reverse_rotate_rotate(t_list **pile_a, t_list **pile_b)
{
	if ((ft_lstsize(*pile_a) < 2) || (ft_lstsize(*pile_b) < 2))
		return (-1);
	reverse_rotate(pile_a);
	reverse_rotate(pile_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
