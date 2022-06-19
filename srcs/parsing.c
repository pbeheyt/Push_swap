/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/19 05:16:25 by pbeheyt          ###   ########.fr       */
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
        free(args[i]);
        if (data->error || check_duplicate(*list, data)) 
        {
            ft_lstclear(list);
            free (args);
            ft_putstr_fd("Error\n", 2);
            return (-1);
        }
        data->index = -1;
        new_element = ft_lstnew(data->nb);
        ft_lstadd_back(list, new_element);
    }
    free(args);
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
        if (data->error || check_duplicate(*list, data)) 
        {
            ft_lstclear(list);
            ft_putstr_fd("Error\n", 2);
            return ;
        }
        data->index = -1;
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

t_list	*get_next_min(t_list **list)
{
	t_list	*min;
	t_list	*tmp;
	int		first;
	
	tmp = *list;
	min = NULL;
	first = 0;
	while (tmp)
	{
		if (tmp->index == -1 && (!first || tmp->nb < min->nb))
		{	
			min = tmp;
			first = 1;
		}
	tmp = tmp->next;
	}
	return (min);
}

void	sort_index(t_list **list)
{
	int		index;
	int		listlen;
	t_list	*tmp;
	
	index = 0;
	listlen = ft_lstsize(*list);
	while (listlen--)
	{
		tmp = get_next_min(list);
		tmp->index = index++;
	}
}