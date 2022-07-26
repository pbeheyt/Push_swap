/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/26 08:33:03 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static void	rotate_list(t_list **list)
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

void	rotate(t_list **list_a, t_list **list_b, int instr)
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

static void	reverse_rotate_list(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp_prev;

	tmp = *list;
	tmp_prev = NULL;
	while (tmp->next)
	{
		tmp_prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = *list;
	tmp_prev->next = NULL;
	*list = tmp;
}

void	reverse_rotate(t_list **list_a, t_list **list_b, int instr)
{
	if (instr == RRA)
	{
		reverse_rotate_list(list_a);
		ft_putstr_fd("rra\n", 1);
	}		
	if (instr == RRB)
	{
		reverse_rotate_list(list_b);
		ft_putstr_fd("rrb\n", 1);
	}
	if (instr == RRR)
	{
		reverse_rotate_list(list_a);
		reverse_rotate_list(list_b);
		ft_putstr_fd("rrr\n", 1);
	}	
}
