/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/19 02:48:28 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Push_swap.h"

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
}

int main(int ac, char **av)
{
	t_list 	*list_a;
	t_list	*list_b;
	t_data	data;
	int		nb_args;
	
	data.error = 0;
	list_a = NULL;
	list_b = NULL;
	printf("nb args : %d\n", fill_list(ac, av, &data, &list_a));
	nb_args = fill_list(ac, av, &data, &list_a);
	print_list(list_a, list_b);
	sort_index(&list_a);
	if (nb_args >= 6)
		sort_list(&list_a, &list_b);
	else if (nb_args >= 2)
		sort_short_list(&list_a, &list_b, nb_args);
	print_list(list_a, list_b);
	// rotate(&list_a, &list_b, RA);
	// print_list(list_a, list_b);
	// reverse_rotate(&list_a, &list_b, RRA);
	// print_list(list_a, list_b);
	// print la liste
	// print_list(list_a, list_b);
	// sort_index(&list_a);
	// print_list(list_a, list_b);
	// sort_list(&list_a, &list_b);
	// print_list(list_a, list_b);
	
	return (1);
}