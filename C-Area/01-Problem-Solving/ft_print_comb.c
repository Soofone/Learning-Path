/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-had <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:57:58 by soel-had          #+#    #+#             */
/*   Updated: 2025/08/14 12:04:18 by soel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = '0';
	while (num1 <= '7')
	{
		num2 = num1 + 1;
		while (num2 <= '8')
		{
			num3 = num2 + 1;
			while (num3 <= '9')
			{
				write (1, &num1, 1);
				write (1, &num2, 1);
				write (1, &num3, 1);
				if (!(num1 == '7' && num2 == '8' && num3 == '9'))
					write (1, ", ", 2);
				num3++;
			}
			num2++;
		}
		num1++;
	}
}
