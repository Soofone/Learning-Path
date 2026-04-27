/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-had <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 10:18:16 by soel-had          #+#    #+#             */
/*   Updated: 2025/11/06 08:25:07 by soel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_whitespace_and_sign(const char *nptr, int *i)
{
	int	sign;

	sign = 1;
	while (nptr[*i] == 32 || (9 <= nptr[*i] && nptr[*i] <= 13))
		(*i)++;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int				i;
	unsigned long	number;
	int				sign;

	i = 0;
	number = 0;
	sign = ft_skip_whitespace_and_sign(nptr, &i);
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - '0');
		if (sign == 1 && number > LONG_MAX)
			return (-1);
		if (sign == -1 && number > (unsigned long)LONG_MAX + 1)
			return (0);
		i++;
	}
	return ((int)(number * sign));
}
