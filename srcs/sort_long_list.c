/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/19 05:39:40 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	find_max_bits(int listlen)
{
	int	max_bits;

	max_bits = 0;
	listlen--;
	while ((listlen >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_long_list(t_list **list_a, t_list **list_b)
{
	int		i;
	int		j;
	int		listlen;
	int		max_bits;
	t_list	*tmp;

	i = -1;
	listlen = ft_lstsize(*list_a);
	max_bits = find_max_bits(listlen);
	while (++i < max_bits)
	{
		j = -1;
		while (++j < listlen)
		{
			tmp = *list_a;
			if (((tmp->index >> i) & 1) == 1)
				rotate(list_a, list_b, RA);
			else
				push(list_a, list_b, PB);
		}
		tmp = *list_b;
		while (ft_lstsize(*list_b))
			push(list_a, list_b, PA);
	}
}
