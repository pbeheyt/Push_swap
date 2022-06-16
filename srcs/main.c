/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/16 06:49:03 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Push_swap.h"

// static void   print_list(t_list *list_a, t_list *list_b)
// {
// 	t_list	*tmp;
	
// 	printf("LISTE A  | len : %d\n", ft_lstsize(list_a));
// 	tmp = list_a;
// 	while (tmp)
// 	{
// 		printf("nb: %d | index : %d\n", tmp->nb, tmp->index);
// 		tmp = tmp->next;
// 	}
// 	printf("---------------\n");
// 	tmp = list_b;
// 	printf("LISTE B  | len : %d\n", ft_lstsize(list_b));
// 	while (tmp)
// 	{
// 		printf("nb: %d | index : %d\n", tmp->nb, tmp->index);
// 		tmp = tmp->next;
// 	}
// 	printf("\n\n");
// }

int main(int ac, char **av)
{
	t_list     *list_a;
	t_list     *list_b;
	t_data     data;
	
	data.error = 0;
	list_a = NULL;
	list_b = NULL;
	fill_list(ac, av, &data, &list_a);
	// print la liste
	// print_list(list_a, list_b);
	sort_index(&list_a);
	// print_list(list_a, list_b);
	sort_list(&list_a, &list_b);
	// print_list(list_a, list_b);
	
	return (1);
}