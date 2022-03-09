/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_and_less.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:20:31 by emmacariot        #+#    #+#             */
/*   Updated: 2022/03/09 13:31:00 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_min(t_list **piles, int val)
{
	t_list	*head;
	int		min;

	head = *piles;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if (head->index < min && head->index != val)
			min = head->index;
	}
	return (min);
}

static void	sort_3_and_less(t_list **pile_a)
{
	t_list	*head;
	int		top;
	int		middle;
	int		bot;

	head = *pile_a;
	top = head->value;
	middle = head->next->value;
	bot = head->next->next->value;
	if (middle < top && middle < bot && bot > top)
		swap_a(pile_a);
	else if (middle < top && middle < bot && top > bot)
		rotate_a(pile_a);
	else if (middle > top && middle > bot && top > bot)
		reverse_rotate_a(pile_a);
	else if (middle > bot && middle < top)
	{
		swap_a(pile_a);
		reverse_rotate_a(pile_a);
	}
	else if (middle > top && middle > bot && bot > top)
	{
		swap_a(pile_a);
		rotate_a(pile_a);
	}
}

static void	sort_4_and_less(t_list **pile_a, t_list **pile_b)
{
	int	distance;

	if (already_sorted(pile_a))
		return ;
	distance = get_distance(pile_a, get_min(pile_a, -1));
	if (distance == 1)
		rotate_a(pile_a);
	else if (distance == 2)
	{
		rotate_a(pile_a);
		rotate_a(pile_a);
	}
	else if (distance == 3)
		reverse_rotate_a(pile_a);
	if (already_sorted(pile_a))
		return ;
	push_b(pile_a, pile_b);
	sort_3_and_less(pile_a);
	push_a(pile_a, pile_b);
}

void	sort_5_and_less(t_list **pile_a, t_list **pile_b)
{
	int	distance;

	distance = get_distance(pile_a, get_min(pile_a, -1));
	if (distance == 1)
		rotate_a(pile_a);
	else if (distance == 2)
	{
		rotate_a(pile_a);
		rotate_a(pile_a);
	}
	else if (distance == 3)
	{
		reverse_rotate_a(pile_a);
		reverse_rotate_a(pile_a);
	}
	else if (distance == 4)
		reverse_rotate_a(pile_a);
	if (already_sorted(pile_a))
		return ;
	push_b(pile_a, pile_b);
	sort_4_and_less(pile_a, pile_b);
	push_a(pile_a, pile_b);
}

void	recap_sort(t_list **pile_a, t_list **pile_b)
{
	int	size;

	if (already_sorted(pile_a) || ft_lstsize(*pile_a) == 0
		|| ft_lstsize(*pile_a) == 1)
		return ;
	size = ft_lstsize(*pile_a);
	if (size == 2)
		swap_a(pile_a);
	else if (size == 3)
		sort_3_and_less(pile_a);
	else if (size == 4)
		sort_4_and_less(pile_a, pile_b);
	else if (size == 5)
		sort_5_and_less(pile_a, pile_b);
}
