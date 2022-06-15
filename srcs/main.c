/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/15 05:49:35 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Push_swap.h"

static void   print_list(t_list *listA, t_list *listB)
{
	t_list	*tmp;
	
	printf("LISTE A  | len : %d\n", ft_lstsize(listA));
	tmp = listA;
	while (tmp)
	{
		printf("nb: %d | index : %d\n", tmp->nb, tmp->index);
		tmp = tmp->next;
	}
	printf("---------------\n");
	tmp = listB;
	printf("LISTE B  | len : %d\n", ft_lstsize(listB));
	while (tmp)
	{
		printf("nb: %d | index : %d\n", tmp->nb, tmp->index);
		tmp = tmp->next;
	}
	printf("\n\n");
}

int main(int ac, char **av)
{
	t_list     *listA;
	t_list     *listB;
	t_data     data;
	
	data.error = 0;
	listA = NULL;
	listB = NULL;
	fill_list(ac, av, &data, &listA);
	// print la liste
	print_list(listA, listB);
	sort_index(&listA);
	print_list(listA, listB);
	// pushB(&listA, &listB);
	// print_list(listA, listB);
	// pushB(&listA, &listB);
	// print_list(listA, listB);
	// rotate_all(&listA, &listB);
	// print_list(listA, listB);
	sort_list(&listA, &listB);
	print_list(listA, listB);
	
	return (1);
}