/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:34:40 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/14 06:32:26 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str, int *error)
{
	long		nblong;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	nblong = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{	
		sign = -sign;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nblong = nblong * 10 + str[i] - '0';
		i++;
	}
	if (str[i])
		*error = 1;
	if (nblong * sign < INT_MIN || nblong * sign > INT_MAX)
        *error = 1;
	return (nblong * sign);
}
/*
int	main(void)
{
	char str[] = "0";
	printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str));
}*/