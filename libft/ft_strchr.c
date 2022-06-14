/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:47:15 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/05/09 19:17:54 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	j;

	j = 0;
	while (str[j] != 0)
	{
		if ((unsigned char)c == str[j])
			return ((char *) str + j);
	j++;
	}
	if (c == 0)
		return ((char *) str + j);
	return (0);
}
/*
int main (void)
{
	char o[] = "salut ca va";
	char u = '\0';

	printf("%p\n", ft_strchr(o, u));
	printf("%p\n", strchr(o, u));
return (0);
}*/