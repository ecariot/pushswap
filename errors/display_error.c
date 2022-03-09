/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:37:22 by emcariot          #+#    #+#             */
/*   Updated: 2022/03/09 15:16:42 by emcariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}

void	ft_error_tab(char **str, char *s)
{
	ft_free(str);
	display_error(s);
}