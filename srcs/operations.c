/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/16 06:50:47 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void push(t_list **list_a, t_list **list_b, int instr)
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

void push_element(t_list **list_from, t_list **list_to)
{
	t_list  *head_from;
	t_list  *head_to;
	t_list  *tmp;
	
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

void rotate(t_list **list_a, t_list **list_b, int instr)
{
{
	if (instr == RA)
	{
		rotate_list(list_a);
		ft_putstr_fd("ra\n", 1);
	}		
	if (instr == RB)
	{
		rotate_list(list_b);
		ft_putstr_fd("rb\n", 1);
	}
	if (instr == RR)
	{
		rotate_list(list_a);
		rotate_list(list_b);
		ft_putstr_fd("rr\n", 1);
	}	
}
}

void rotate_list(t_list **list)
{
	t_list	*head;
	t_list	*tail;

	head = *list;
	tail = ft_lstlast(*list);

	if (!head->next)
		return ;
	*list = head->next;
	tail->next = head;
	head->next = NULL;
}
