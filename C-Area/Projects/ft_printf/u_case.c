/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-had <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:21:31 by soel-had          #+#    #+#             */
/*   Updated: 2025/11/10 16:22:12 by soel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_case(va_list args, int *k, int *j)
{
	unsigned int	u;

	u = va_arg(args, unsigned int);
	*k += ft_putnbr_unsigned(u);
	(*j)++;
}
