/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/08/19 02:13:16 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;
	int		error;
	int		nb_args;

	list_a = NULL;
	list_b = NULL;
	error = 0;
	nb_args = fill_list(ac, av, &error, &list_a);
	if (error)
		return (ft_putstr_fd("Error\n", 2), -1);
	sort_index(&list_a);
	if (is_sorted(&list_a))
		return (ft_lstclear(&list_a), 0);
	if (nb_args >= 6)
		sort_long_list(&list_a, &list_b);
	else if (nb_args >= 2)
		sort_short_list(&list_a, &list_b, nb_args);
	ft_lstclear(&list_a);
	ft_lstclear(&list_b);
	return (0);
}
