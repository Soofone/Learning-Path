/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-had <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:35:11 by soel-had          #+#    #+#             */
/*   Updated: 2025/11/10 18:19:41 by soel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putnbr_unsigned(unsigned int u)
{
	char	c;
	int		k;

	k = 0;
	if (u < 0)
		return (0);
	if (u >= 10)
		k += ft_putnbr_unsigned(u / 10);
	c = (u % 10) + '0';
	k += ft_putchar(c);
	return (k);
}
