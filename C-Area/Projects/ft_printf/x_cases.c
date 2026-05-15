/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_cases.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-had <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:24:40 by soel-had          #+#    #+#             */
/*   Updated: 2025/11/10 16:25:35 by soel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_cases(va_list args, int *k, int *j, char upper)
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	*k += print_hex((unsigned int)x, upper);
	(*j)++;
}
