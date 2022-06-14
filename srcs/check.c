/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/14 05:05:25 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int check_duplicate(t_list *lst, int nb)
{
    t_list  *tmp;
    
    tmp = lst;
    while (tmp)
    {
        if (nb == tmp->nb)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}