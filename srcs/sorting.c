/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/30 09:45:41 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static t_list	*get_next_min(t_list **list)
{
	t_list	*min;
	t_list	*tmp;
	int		first;

	tmp = *list;
	min = NULL;
	first = 0;
	while (tmp)
	{
		if (tmp->index == -1 && (!first || tmp->nb < min->nb))
		{	
			min = tmp;
			first = 1;
		}
	tmp = tmp->next;
	}
	return (min);
}

void	sort_index(t_list **list)
{
	int		index;
	int		listlen;
	t_list	*tmp;

	index = 0;
	listlen = ft_lstsize(*list);
	while (listlen--)
	{
		tmp = get_next_min(list);
		tmp->index = index++;
	}
}

int	is_sorted(t_list **list)
{
	t_list	*tmp;

	if (!*list)
		return (1);
	tmp = *list;
	while (tmp->next)
	{
		if (tmp->index >= tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
