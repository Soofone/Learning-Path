/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-had <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:50:40 by soel-had          #+#    #+#             */
/*   Updated: 2025/11/10 12:55:43 by soel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	counter;

	if (!s)
		return (0);
	i = 0;
	counter = 0;
	while (s[i])
		counter += ft_putchar(s[i++]);
	return (counter);
}
