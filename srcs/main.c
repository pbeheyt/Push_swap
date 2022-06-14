/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/14 07:12:52 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Push_swap.h"

int main(int ac, char **av)
{
    t_list     *listA;
    t_list     *listB;
    t_list     *tmp;
	t_data     data;
    
    (void)listB;
    // lst->index = 0;
    data.error = 0;
    listA = NULL;
    listB = NULL;
	fill_list(ac, av, &data, &listA);
    tmp = listA;
    while (tmp)
    {
        printf("nb: %d | index : %d\n", tmp->nb, 0);
        tmp = tmp->next;
    }
    return (1);
}