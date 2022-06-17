/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/17 05:35:25 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int fill_list_str_arg(char **av, t_data *data, t_list **list)
{
    int     i;
    char    **args;
    t_list  *new_element;

    args = ft_split(av[1], ' ');
    i = -1;
    while (args[++i])
    {
        data->nb = ft_atoi(args[i], &data->error);
        data->index = -1;
        if (check_duplicate(*list, data->nb))
        {  
            ft_putstr_fd("Error", 2);
            return (-1);
        }
        new_element = ft_lstnew(data->nb);
        ft_lstadd_back(list, new_element);
    }
    return (i);
}

void fill_list_multiple_args(int ac, char **av, t_data *data, t_list **list)
{
    int     i;
    t_list  *new_element;

    i = 0;
    while (++i < ac)
    {
        data->nb = ft_atoi(av[i], &data->error);
        data->index = -1;
        if (check_duplicate(*list, data->nb))
        {  
            ft_putstr_fd("Error", 2);
            return ;
        }
        new_element = ft_lstnew(data->nb);
        ft_lstadd_back(list, new_element);
    }
}

int fill_list(int ac, char **av, t_data *data, t_list **list)
{
    if (ac == 2)
        return (fill_list_str_arg(av, data, list));
    if (ac > 2)
        fill_list_multiple_args(ac, av, data, list);
    return (ac - 1);
}