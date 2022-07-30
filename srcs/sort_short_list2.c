/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_list2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/30 09:25:29 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static void	sort_three_min_index_two(t_list **list_a, t_list **list_b,
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

static void	sort_three_min_index_zero(t_list **list_a, t_list **list_b,
t_list	*second_element, t_list	*third_element)
{
	if (second_element->nb > third_element->nb)
	{
		swap(list_a, list_b, SA);
		rotate(list_a, list_b, RA);
	}
}

static void	sort_three_min_index_one(t_list **list_a, t_list **list_b,
t_list	*first_element, t_list	*third_element)
{
	if (first_element->nb < third_element->nb)
		swap(list_a, list_b, SA);
	else if (first_element->nb > third_element->nb)
		rotate(list_a, list_b, RA);
}

void	sort_three(t_list **list_a, t_list **list_b, int min_index_value)
{
	int		min_index_pos;
	t_list	*first_elem;
	t_list	*second_elem;
	t_list	*third_elem;

	min_index_pos = get_min_index_pos(list_a, min_index_value);
	first_elem = *list_a;
	second_elem = first_elem->next;
	third_elem = second_elem->next;
	if (min_index_pos == 0)
		sort_three_min_index_zero(list_a, list_b, second_elem, third_elem);
	if (min_index_pos == 1)
		sort_three_min_index_one(list_a, list_b, first_elem, third_elem);
	if (min_index_pos == 2)
		sort_three_min_index_two(list_a, list_b, first_elem, second_elem);
}
