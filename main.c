/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:16:34 by emcariot          #+#    #+#             */
/*   Updated: 2022/03/09 15:56:34 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	fill_stack(t_list **stack, int ac, char **av)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (ac == 2)
		ft_free(args);
}

int	already_sorted(t_list **piles)
{
	t_list	*head;

	head = *piles;
	while (head->next)
	{
		if (head->value < head->next->value && head->next)
			head = head->next;
		else
			return (0);
	}
	return (1);
}

static void	final_sorting(t_list **pile_a, t_list **pile_b)
{
	if (ft_lstsize(*pile_a) <= 5)
		recap_sort(pile_a, pile_b);
	else
		radix_sort(pile_a, pile_b);
}

int	main(int ac, char **av)
{
	t_list	**pile_a;
	t_list	**pile_b;

	if (ac < 2)
		return (-1);
	if (ac == 2 && av[1][0] == '\0')
		display_error("Error");
	check_args(ac, av);
	pile_a = (t_list **)malloc(sizeof(t_list));
	pile_b = (t_list **)malloc(sizeof(t_list));
	*pile_a = NULL;
	*pile_b = NULL;
	fill_stack(pile_a, ac, av);
	if (already_sorted(pile_a) == 1)
	{
		free_stack(pile_a);
		free_stack(pile_b);
		return (0);
	}
	final_sorting(pile_a, pile_b);
	free_stack(pile_a);
	free_stack(pile_b);
	return (0);
}
