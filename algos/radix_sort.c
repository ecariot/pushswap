/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:19:07 by emcariot          #+#    #+#             */
/*   Updated: 2022/03/08 12:23:17 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_bytes(t_list **piles)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *piles;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **pile_a, t_list **pile_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *pile_a;
	size = ft_lstsize(head_a);
	max_bits = get_bytes(pile_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *pile_a;
			if (((head_a->index >> i) & 1) == 1)
				rotate_a(pile_a);
			else
				push_b(pile_a, pile_b);
		}
		while (ft_lstsize(*pile_b) != 0)
			push_a(pile_a, pile_b);
		i++;
	}
}
