/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 04:41:55 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/15 05:19:48 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

typedef struct s_data
{
	int	error;
	int	nb;
	int	index;
}			t_data;

enum e_instr
{
	PA,
	PB,
	RA,
	RB
};

int check_duplicate(t_list *lst, int nb);
void fill_list(int ac, char **av, t_data *data, t_list **listA);
void pushA(t_list **listA, t_list **listB);
void pushB(t_list **listA, t_list **listB);
void rotate(t_list **list);
void rotate_all(t_list **listA, t_list **listB);
int	find_max_bits(int listlen);
void	sort_list(t_list **listA, t_list **listB);
t_list	*get_next_min(t_list **list);
void	sort_index(t_list **list);

#endif