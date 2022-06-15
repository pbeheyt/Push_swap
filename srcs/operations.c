/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/16 01:15:44 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

// t_list  add_element(t_list **listA, t_list **listB, t_data *data)
// {
// 		t_list *new_element;
		
// 		new_element = ft_lstnew(data->nb);
// 		ft_lstadd_back(listA, new_element);
// }
void pushB(t_list **list_a, t_list **list_b)
{
		t_list  *headA;
		t_list  *headB;
		t_list  *tmp;
		
		headA = *list_a;
		headB = *list_b;
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
		*list_a = headA;
		*list_b = headB;
}

void pushA(t_list **list_a, t_list **list_b)
{
		t_list  *headA;
		t_list  *headB;
		t_list  *tmp;
		
		headA = *list_a;
		headB = *list_b;
		if (!headB)
			return ;
		tmp = list_b;
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
		*list_a = headA;
		*list_b = headB;
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

void rotate_all(t_list **list_a, t_list **list_b)
{
	rotate(list_a);
	rotate(list_b);
}