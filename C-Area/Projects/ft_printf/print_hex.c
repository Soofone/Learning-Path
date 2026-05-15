/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-had <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:24:32 by soel-had          #+#    #+#             */
/*   Updated: 2025/11/10 16:59:03 by soel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long p, char upper)
{
	char		*hex;
	char		c;
	int			k;

	k = 0;
	hex = "0123456789abcdef";
	if (p >= 16)
		k += print_hex(p / 16, upper);
	c = hex[p % 16];
	if (upper == 'y' && 'a' <= c && c <= 'z')
		c -= 32;
	write(1, &c, 1);
	k++;
	return (k);
}
