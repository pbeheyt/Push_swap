/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/30 10:08:28 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

/*
static void   print_list(t_list *list_a, t_list *list_b)
{
	t_list	*tmp;
	
	printf("LISTE A  | len : %d\n", ft_lstsize(list_a));
	tmp = list_a;
	while (tmp)
	{
		printf("nb: %d | index : %d\n", tmp->nb, tmp->index);
		tmp = tmp->next;
	}
	printf("---------------\n");
	tmp = list_b;
	printf("LISTE B  | len : %d\n", ft_lstsize(list_b));
	while (tmp)
	{
		printf("nb: %d | index : %d\n", tmp->nb, tmp->index);
		tmp = tmp->next;
	}
	printf("\n\n");
}*/

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
	// print_list(list_a, list_b);
	if (is_sorted(&list_a))
		return (ft_lstclear(&list_a), 0);
	if (nb_args >= 6)
		sort_long_list(&list_a, &list_b);
	else if (nb_args >= 2)
		sort_short_list(&list_a, &list_b, nb_args);
	// print_list(list_a, list_b);
	ft_lstclear(&list_a);
	ft_lstclear(&list_b);
	return (0);
}
