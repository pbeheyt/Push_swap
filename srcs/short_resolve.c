/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_resolve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/17 07:00:56 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	sort_short_list(t_list **list_a, t_list **list_b, int nb_args)
{
	if (nb_args == 3)
		sort_three(list_a, list_b);
	if (nb_args == 4)
		sort_three(list_a, list_b);
	if (nb_args == 5)
		sort_three(list_a, list_b);
}

int	get_index_min(t_list **list)
{
	t_list	*tmp;
	int		index;
	
	index = 0;
	tmp = *list;
	while (tmp)
	{
		if (tmp->index == 0)
			return (index);
		index++;
	tmp = tmp->next;
	}
	return (index);
}

void	sort_three(t_list **list_a, t_list **list_b)
{
	int		min_index;
	t_list	*first_element;
	t_list	*second_element;
	t_list	*third_element;
	
	min_index = get_index_min(list_a);
	first_element = *list_a;
	second_element = first_element->next;
	third_element = second_element->next; 
	if (min_index == 0)
		sort_three_min_index_zero(list_a, list_b, second_element, third_element);
	if (min_index == 1)
		sort_three_min_index_one(list_a, list_b, first_element, third_element);
	if (min_index == 2)
		sort_three_min_index_two(list_a, list_b, first_element, second_element);
	
}

void	sort_three_min_index_zero(t_list **list_a, t_list **list_b, 
t_list	*second_element, t_list	*third_element)
{
	if (second_element->nb > third_element->nb)
	{
		swap(list_a, list_b, SA);
		rotate(list_a, list_b, RA);
	}
}

void	sort_three_min_index_one(t_list **list_a, t_list **list_b, 
t_list	*first_element, t_list	*third_element)
{
	if (first_element->nb < third_element->nb)
		swap(list_a, list_b, SA);
	else if (first_element->nb > third_element->nb)
		rotate(list_a, list_b, RA);
}

void	sort_three_min_index_two(t_list **list_a, t_list **list_b, 
t_list	*first_element, t_list	*second_element)
{
	if (first_element->nb < second_element->nb)
		reverse_rotate(list_a, list_b, RRA);
	else if (first_element->nb > second_element->nb)
	{	
		rotate(list_a, list_b, RA);
		swap(list_a, list_b, SA);
	}
}
