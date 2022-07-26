/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/21 15:46:47 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	check_duplicate(t_list *list, t_data *data)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (data->nb == tmp->nb)
		{
			data->error = 1;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	is_sorted(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp->next)
	{
		if (tmp->index >= tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
