/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:57:37 by emcariot          #+#    #+#             */
/*   Updated: 2022/03/09 15:21:34 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_convert(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_args(int ac, char **av)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (ac == 2)
	{
		if (av[1][0] == '\0')
			ft_error_tab(av, "Error");
		args = ft_split(av[1], ' ');
	}
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error_tab(args, "Error");
		if (ft_convert(tmp, args, i))
			display_error("Error");
		if (tmp < INT_MIN || tmp > __INT_MAX__)
			display_error("Error");
		i++;
	}
	if (ac == 2)
		ft_free(args);
}
