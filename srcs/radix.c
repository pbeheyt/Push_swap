/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/15 05:56:05 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

t_list	*get_next_min(t_list **list)
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
	// tmp = get_next_min(list);
	while (listlen--)
	{
		tmp = get_next_min(list);
		tmp->index = index++;
	}
}

int	find_max_bits(int listlen)
{
	int	max_bits;

	max_bits = 0;
	listlen--;
	while ((listlen >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_list(t_list **listA, t_list **listB)
{
	int	i;
	int	listlen;
	int	max_bits;
	t_list	*tmp;

	(void)listB; 
	i = -1;
	listlen = ft_lstsize(*listA);
	max_bits = find_max_bits(listlen);
	printf("nb de bits %d\n", max_bits);
	while (++i < max_bits)
	{
		while (listlen--)
		{
			tmp = *listA;
			if (tmp->index >> i & 1)
				pushA(listA, listB);
			else
				rotate(listA);
		}
		tmp = *listB;
		while (tmp)
		{
			pushB(listA, listB);
			tmp = tmp->next;
		}
	}
}