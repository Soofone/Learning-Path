/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-had <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:49:38 by soel-had          #+#    #+#             */
/*   Updated: 2025/11/14 10:35:54 by soel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	cases(const char *str, va_list args, int *k, int *j)
{
	if (str[*j + 1] == 'c')
		c_case(args, k, j);
	else if (str[*j + 1] == 's')
		s_case(args, k, j);
	else if (str[*j + 1] == 'p')
		p_case(args, k, j);
	else if (str[*j + 1] == 'd' || str[*j + 1] == 'i')
		i_d_case(args, k, j);
	else if (str[*j + 1] == 'u')
		u_case(args, k, j);
	else if (str[*j + 1] == 'x')
		x_cases(args, k, j, 'n');
	else if (str[*j + 1] == 'X')
		x_cases(args, k, j, 'y');
	else if (str[*j + 1] == '%')
	{
		*k += ft_putchar('%');
		(*j)++;
	}
	else
	{
		*k += ft_putchar('%');
		*k += ft_putchar(str[*j + 1]);
		(*j)++;
	}
}

static int	handle_percent(const char *str, va_list args, int *k, int *j)
{
	int	len_str;

	len_str = ft_strlen(str);
	if (*j + 1 == len_str)
		return (-1);
	else
		cases(str, args, k, j);
	return (0);
}

static void	func_vars(const char *str, int *len_str, int *j, int *k)
{
	*len_str = ft_strlen(str);
	*j = 0;
	*k = 0;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len_str;
	int		j;
	int		k;
	int		result;

	if (!str || write(1, "", 0) == -1)
		return (-1);
	func_vars(str, &len_str, &j, &k);
	va_start(args, str);
	while (j < len_str)
	{
		if (str[j] == '%')
		{
			result = handle_percent(str, args, &k, &j);
			if (result == -1)
				return (-1);
		}
		else
			k += ft_putchar(str[j]);
		j++;
	}
	va_end(args);
	return (k);
}
