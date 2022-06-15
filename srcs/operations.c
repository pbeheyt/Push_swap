/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/15 03:40:43 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

// t_list  add_element(t_list **listA, t_list **listB, t_data *data)
// {
// 		t_list *new_element;
		
// 		new_element = ft_lstnew(data->nb);
// 		ft_lstadd_back(listA, new_element);
// }
void pushB(t_list **listA, t_list **listB)
{
		t_list  *headA;
		t_list  *headB;
		t_list  *tmp;
		
		headA = *listA;
		headB = *listB;
		if (!headA)
			return ;
		tmp = headA;
		headA = headA->next;
		if (!headB)
		{
			headB = tmp;
			headB->next = NULL;			
		}
		else
		{
			tmp->next = headB;
			headB = tmp;	
		}
		*listA = headA;
		*listB = headB;
}

void pushA(t_list **listA, t_list **listB)
{
		t_list  *headA;
		t_list  *headB;
		t_list  *tmp;
		
		headA = *listA;
		headB = *listB;
		if (!headB)
			return ;
		tmp = headB;
		headB = headB->next;
		if (!headA)
		{
			headA = tmp;
			headA->next = NULL;			
		}
		else
		{
			tmp->next = headA;
			headA = tmp;	
		}
		*listA = headA;
		*listB = headB;
}

void rotate(t_list **list)
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

void rotate_all(t_list **listA, t_list **listB)
{
	rotate(listA);
	rotate(listB);
}