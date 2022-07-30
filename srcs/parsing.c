/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:23:24 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/30 10:04:12 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	check_duplicate(t_list *list, int nb, int *error)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (nb == tmp->nb)
		{
			*error = 1;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static void	free_tab(char **tab)
{	
	int	i;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free (tab);
}

static int	fill_list_str_arg(char **av, int *error, t_list **list)
{
	int		i;
	int		nb;
	char	**args;
	t_list	*new_element;

	args = ft_split(av[1], ' ');
	i = -1;
	while (args[++i])
	{
		nb = ft_atoi(args[i], error);
		if (*error == 1 || check_duplicate(*list, nb, error))
		{
			ft_lstclear(list);
			free_tab(args);
			return (-1);
		}
		new_element = ft_lstnew(nb);
		ft_lstadd_back(list, new_element);
	}
	free_tab(args);
	return (i);
}

static void	fill_list_multiple_args(int ac, char **av, int *error,
	t_list **list)
{
	int		i;
	int		nb;
	t_list	*new_element;

	i = 0;
	while (++i < ac)
	{
		nb = ft_atoi(av[i], error);
		if (*error == 1 || check_duplicate(*list, nb, error))
		{
			ft_lstclear(list);
			return ;
		}
		new_element = ft_lstnew(nb);
		ft_lstadd_back(list, new_element);
	}
}

int	fill_list(int ac, char **av, int *error, t_list **list)
{
	if (ac == 2)
		return (fill_list_str_arg(av, error, list));
	if (ac > 2)
		fill_list_multiple_args(ac, av, error, list);
	return (ac - 1);
}
