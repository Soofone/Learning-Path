/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-had <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:18:35 by soel-had          #+#    #+#             */
/*   Updated: 2025/11/13 09:06:02 by soel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_case(va_list args, int *k, int *j)
{
	void	*p;

	p = va_arg(args, void *);
	if (p == 0)
		*k += ft_putstr("(nil)");
	else
	{
		*k += ft_putstr("0x");
		*k += print_hex((unsigned long)p, 'n');
	}
	(*j)++;
}
