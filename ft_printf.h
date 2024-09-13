/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenc <egenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:57:13 by egenc             #+#    #+#             */
/*   Updated: 2022/02/17 15:09:35 by egenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *s, ...);
int	ft_formats(va_list ap, char c);

int	ft_putchar(int c);
int	ft_putstr(char *s);

int	ft_putnbr(int nbr);
int	ft_put_unsigned(unsigned int nbr);

int	ft_puthex(unsigned long nbr, char c);

#endif