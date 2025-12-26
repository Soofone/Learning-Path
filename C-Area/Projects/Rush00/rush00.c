/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-had <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 09:53:48 by soel-had          #+#    #+#             */
/*   Updated: 2025/08/17 10:43:49 by soel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_header(int x, int y)
{
	ft_putchar('/');
	x--;
	if (x == 0)
	{
		ft_putchar('\n');
	}
	while (x > 1)
	{
		ft_putchar('*');
		x--;
	}
	if (x == 1)
	{
		ft_putchar('\\');
		ft_putchar('\n');
	}
}

void	print_x_in_middle_part(int x, int y, int cols)
{
	while (y > 0)
	{
		ft_putchar('*');
		while (x - 2 > 0)
		{
			write(1, " ", 1);
			x--;
		}
		x = cols;
		write(1, "*\n", 2);
		y--;
	}
}

void	print_middle(int x, int y)
{
	int	cols;

	if (x > 1)
	{
		if (y >= 3)
		{
			y = y - 2;
			cols = x;
			print_x_in_middle_part(x, y, cols);
		}
	}
	if (x == 1)
	{
		while (y > 2)
		{
			write(1, "*\n", 2);
			y--;
		}
	}
}

void	print_footer(int x, int y)
{
	if (y > 1)
	{
		ft_putchar('\\');
		x--;
		while (x > 1)
		{
			ft_putchar('*');
			x--;
		}
		if (x == 1)
		{
			ft_putchar('/');
			ft_putchar('\n');
		}
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		write(1, "Enter only non-zero integer positive numbers!\n", 46);
	}
	else
	{
		print_header(x, y);
		print_middle(x, y);
		print_footer(x, y);
	}
}
