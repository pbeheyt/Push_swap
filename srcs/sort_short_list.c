/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/08/19 01:35:47 by pbeheyt          ###   ########.fr       */
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

void	sort_two(t_list **list_a, t_list **list_b, int min_index_value)
{
	int		min_index_pos;

	min_index_pos = get_min_index_pos(list_a, min_index_value);
	if (min_index_pos == 1)
		swap(list_a, list_b, SA);
}

void	sort_four(t_list **list_a, t_list **list_b, int min_index_value)
{
	int		min_index_pos;
	int		listlen;
	int		reverse;
	t_list	*head;

	min_index_pos = get_min_index_pos(list_a, min_index_value);
	listlen = ft_lstsize(*list_a);
	reverse = 0;
	head = *list_a;
	if (min_index_pos > listlen / 2)
		reverse = 1;
	while (head->index != min_index_value)
	{
		if (!reverse)
			rotate(list_a, list_b, RA);
		else if (reverse)
			reverse_rotate(list_a, list_b, RRA);
		head = *list_a;
	}
	push(list_a, list_b, PB);
	sort_three(list_a, list_b, min_index_value + 1);
	push(list_a, list_b, PA);
}

void	sort_five(t_list **list_a, t_list **list_b, int min_index_value)
{
	int		min_index_pos;
	int		listlen;
	int		reverse;
	t_list	*head;

	min_index_pos = get_min_index_pos(list_a, min_index_value);
	listlen = ft_lstsize(*list_a);
	reverse = 0;
	head = *list_a;
	if (min_index_pos > listlen / 2)
		reverse = 1;
	while (head->index != min_index_value)
	{
		if (!reverse)
			rotate(list_a, list_b, RA);
		else if (reverse)
			reverse_rotate(list_a, list_b, RRA);
		head = *list_a;
	}
	push(list_a, list_b, PB);
	sort_four(list_a, list_b, 1);
	push(list_a, list_b, PA);
}
