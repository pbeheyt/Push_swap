/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_list2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/19 05:53:19 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	get_min_index_pos(t_list **list, int min_index_value)
{
	t_list	*tmp;
	int		min_index_pos;

	min_index_pos = 0;
	tmp = *list;
	while (tmp)
	{
		if (tmp->index == min_index_value)
			return (min_index_pos);
		min_index_pos++;
	tmp = tmp->next;
	}
	return (min_index_pos);
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
