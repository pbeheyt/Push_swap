/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_resolve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/19 02:47:45 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	sort_short_list(t_list **list_a, t_list **list_b, int nb_args)
{
	if (nb_args == 2)
		sort_two(list_a, list_b, 0);
	if (nb_args == 3)
		sort_three(list_a, list_b, 0);
	if (nb_args == 4)
		sort_four(list_a, list_b, 0);
	if (nb_args == 5)
		sort_five(list_a, list_b, 0);
}

void	sort_two(t_list **list_a, t_list **list_b, int min_index_value)
{
	int		min_index_pos;
	
	min_index_pos = get_min_index_pos(list_a, min_index_value);
	if (min_index_pos == 1)
		swap(list_a, list_b, SA);
}

void	sort_three(t_list **list_a, t_list **list_b, int min_index_value)
{
	int		min_index_pos;
	t_list	*first_element;
	t_list	*second_element;
	t_list	*third_element;
	
	min_index_pos = get_min_index_pos(list_a, min_index_value);
	first_element = *list_a;
	second_element = first_element->next;
	third_element = second_element->next; 
	if (min_index_pos == 0)
		sort_three_min_index_zero(list_a, list_b, second_element, third_element);
	if (min_index_pos == 1)
		sort_three_min_index_one(list_a, list_b, first_element, third_element);
	if (min_index_pos == 2)
		sort_three_min_index_two(list_a, list_b, first_element, second_element);
	
}

void	sort_four(t_list **list_a, t_list **list_b, int min_index_value)
{
	int		min_index_pos;
	int		list_len;
	t_list	*head;
	
	min_index_pos = get_min_index_pos(list_a, min_index_value);
	list_len = ft_lstsize(*list_a);
	head = *list_a;
	if (min_index_pos < list_len / 2)
	{
		while (head->index != min_index_value)
		{
			rotate(list_a, list_b, RA);
			head = *list_a;
		}
	}
	else
	{
		while (head->index != min_index_value)
		{
			reverse_rotate(list_a, list_b, RRA);
			head = *list_a;
		}
	}
	push(list_a, list_b, PB);
	sort_three(list_a, list_b, min_index_value + 1);
	push(list_a, list_b, PA);
}

void	sort_five(t_list **list_a, t_list **list_b, int min_index_value)
{
	int		min_index_pos;
	int		list_len;
	t_list	*tmp;
	
	min_index_pos = get_min_index_pos(list_a, min_index_value);
	list_len = ft_lstsize(*list_a);
	tmp = *list_a;
	if (min_index_pos < list_len / 2)
	{
		while (tmp->index != 0)
		{
			rotate(list_a, list_b, RA);
			tmp = *list_a;
		}
	}
	else
	{
		while (tmp->index != 0)
		{
			reverse_rotate(list_a, list_b, RRA);
			tmp = *list_a;
		}
	}
	push(list_a, list_b, PB);
	sort_four(list_a, list_b, 1);
	push(list_a, list_b, PA);
}

