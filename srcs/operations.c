/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/26 08:32:20 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static void	push_element(t_list **list_from, t_list **list_to)
{
	t_list	*head_from;
	t_list	*head_to;
	t_list	*tmp;

	head_from = *list_from;
	head_to = *list_to;
	if (!head_from)
		return ;
	tmp = head_from;
	head_from = head_from->next;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
	}
	else
	{
		tmp->next = head_to;
		head_to = tmp;
	}
	*list_from = head_from;
	*list_to = head_to;
}

void	push(t_list **list_a, t_list **list_b, int instr)
{
	if (instr == PA)
	{
		push_element(list_b, list_a);
		ft_putstr_fd("pa\n", 1);
	}
	if (instr == PB)
	{
		push_element(list_a, list_b);
		ft_putstr_fd("pb\n", 1);
	}		
}

static void	swap_element(t_list **list)
{
	t_list	*head;
	t_list	*first;
	t_list	*second;

	head = *list;
	first = head;
	second = first->next;
	if (!head || !head->next)
		return ;
	first->next = second->next;
	second->next = first;
	*list = second;
}

void	swap(t_list **list_a, t_list **list_b, int instr)
{
	if (instr == SA)
	{
		swap_element(list_a);
		ft_putstr_fd("sa\n", 1);
	}
	if (instr == SB)
	{
		swap_element(list_a);
		ft_putstr_fd("sb\n", 1);
	}
	if (instr == SS)
	{
		swap_element(list_a);
		swap_element(list_b);
		ft_putstr_fd("ss\n", 1);
	}		
}
