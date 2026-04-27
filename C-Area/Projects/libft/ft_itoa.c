/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-had <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:30:33 by soel-had          #+#    #+#             */
/*   Updated: 2025/10/29 15:37:41 by soel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	n = -n;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	fill_str(char *str, int digit_num, int n, int is_negative)
{
	digit_num--;
	while (n > 0)
	{
		str[digit_num] = (n % 10) + '0';
		digit_num--;
		n /= 10;
	}
	if (is_negative)
		str[0] = '-';
}

static char	*allocate_str(int digit_num)
{
	char	*str;

	str = malloc((digit_num + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[digit_num] = '\0';
	return (str);
}

static void	last_part(int is_negative, int n, int digit_num, char *str)
{
	if (is_negative)
		n = -n;
	fill_str(str, digit_num, n, is_negative);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit_num;
	int		is_negative;

	if (n == -2147483648)
	{
		str = malloc(12 * sizeof(char));
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	is_negative = (n < 0);
	digit_num = count_digit(n);
	str = allocate_str(digit_num);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	else
		last_part(is_negative, n, digit_num, str);
	return (str);
}
