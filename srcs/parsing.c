/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/14 23:44:17 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void fill_list(int ac, char **av, t_data *data, t_list **listA)
{
    int     i;
    t_list  *new_element;

    i = 0;
    while (++i < ac)
    {
        data->nb = ft_atoi(av[i], &data->error);
        data->index = -1;
        if (check_duplicate(*listA, data->nb))
        {  
            ft_putstr_fd("Error", 2);
            return ;
        }
        new_element = ft_lstnew(data->nb);
        ft_lstadd_back(listA, new_element);
    }
}