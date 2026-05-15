/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-had <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:49:52 by soel-had          #+#    #+#             */
/*   Updated: 2025/11/12 16:51:40 by soel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				ft_strlen(const char *s);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				print_hex(unsigned long p, char upper);
int				ft_putnbr(int n);
unsigned int	ft_putnbr_unsigned(unsigned int n);
void			c_case(va_list args, int *k, int *j);
void			s_case(va_list args, int *k, int *j);
void			p_case(va_list args, int *k, int *j);
void			i_d_case(va_list args, int *k, int *j);
void			u_case(va_list args, int *k, int *j);
void			x_cases(va_list args, int *k, int *j, char upper);

#endif
