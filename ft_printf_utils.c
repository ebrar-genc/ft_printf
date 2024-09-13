/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenc <egenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:55:52 by egenc             #+#    #+#             */
/*   Updated: 2022/02/17 15:08:33 by egenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		i += write(1, "-2", 2);
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		i += write (1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 0 && nbr <= 9)
		i += ft_putchar(nbr + 48);
	if (nbr > 9)
	{
		i += ft_putnbr(nbr / 10);
		i += ft_putnbr(nbr % 10);
	}
	return (i);
}

int	ft_puthex(unsigned long nbr, char c)
{
	int	i;

	i = 0;
	if (c == 'x')
	{
		if (nbr < 16)
			i += write(1, &"0123456789abcdef"[nbr], 1);
		else
		{
			i += ft_puthex(nbr / 16, c);
			i += ft_puthex(nbr % 16, c);
		}
	}
	else
	{
		if (nbr < 16)
			i += write(1, &"0123456789ABCDEF"[nbr], 1);
		else
		{
			i += ft_puthex(nbr / 16, c);
			i += ft_puthex(nbr % 16, c);
		}
	}
	return (i);
}

int	ft_puthex_up(unsigned long nbr)
{
	int	i;

	i = 0;
	if (nbr < 16)
	{
		if (nbr < 10)
			i += write(1, &"0123456789"[nbr], 1);
		else
			i += write(1, &"0123456789ABCDEF"[nbr], 1);
	}
	else
	{
		i += ft_puthex_up(nbr / 16);
		i += ft_puthex_up(nbr % 16);
	}
	return (i);
}

int	ft_put_unsigned(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		i = write (1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 0 && nbr <= 9)
		i += ft_putchar(nbr + 48);
	if (nbr > 9)
	{
		i += ft_putnbr(nbr / 10);
		i += ft_putnbr(nbr % 10);
	}
	return (i);
}
