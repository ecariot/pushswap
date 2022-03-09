/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:53:31 by emmacariot        #+#    #+#             */
/*   Updated: 2022/03/08 12:45:49 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

int	push_a(t_list **pile_a, t_list **pile_b)
{
	if (push(pile_a, pile_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	push_b(t_list **pile_a, t_list **pile_b)
{
	if (push(pile_b, pile_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
