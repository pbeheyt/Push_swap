/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 04:41:55 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/21 15:45:55 by pbeheyt          ###   ########.fr       */
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
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

/*check.c*/
int		check_duplicate(t_list *list, t_data *data);
int		is_sorted(t_list **list);

/*parsing.c*/
int		fill_list_str_arg(char **av, t_data *data, t_list **list);
void	fill_list_multiple_args(int ac, char **av, t_data *data, t_list **list);
int		fill_list(int ac, char **av, t_data *data, t_list **list);
t_list	*get_next_min(t_list **list);
void	sort_index(t_list **list);

/*operations.c*/
void	push_element(t_list **list_from, t_list **list_to);
void	push(t_list **list_a, t_list **list_b, int instr);
void	swap_element(t_list **list);
void	swap(t_list **list_a, t_list **list_b, int instr);

/*operations2.c*/
void	rotate(t_list **list_a, t_list **list_b, int instr);
void	rotate_list(t_list **list);
void	reverse_rotate(t_list **list_a, t_list **list_b, int instr);
void	reverse_rotate_list(t_list **list);

/*sort_short_list.c*/
void	sort_short_list(t_list **list_a, t_list **list_b, int nb_args);
void	sort_two(t_list **list_a, t_list **list_b, int min_index_value);
void	sort_three(t_list **list_a, t_list **list_b, int min_index_value);
void	sort_four(t_list **list_a, t_list **list_b, int min_index_value);
void	sort_five(t_list **list_a, t_list **list_b, int min_index_value);

/*sort_short_list2.c*/
int		get_min_index_pos(t_list **list, int min_index_value);
void	sort_three_min_index_zero(t_list **list_a, t_list **list_b,
			t_list	*second_element, t_list	*third_element);
void	sort_three_min_index_one(t_list **list_a, t_list **list_b,
			t_list	*first_element, t_list	*third_element);
void	sort_three_min_index_two(t_list **list_a, t_list **list_b,
			t_list	*first_element, t_list	*second_element);

/*sort_long_list.c*/
int		find_max_bits(int listlen);
void	sort_long_list(t_list **list_a, t_list **list_b);

#endif