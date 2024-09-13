/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenc <egenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:57:16 by egenc             #+#    #+#             */
/*   Updated: 2022/02/17 15:09:08 by egenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s && s[i])
		ft_putchar(s[i++]);
	return (i);
}

int	ft_formats(va_list ap, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(ap, int));
	else if (c == 's')
		len = ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(ap, int));
	else if (c == 'x' || c == 'X')
		len = ft_puthex(va_arg(ap, unsigned int), c);
	else if (c == 'p')
	{
		len = write(1, "0x", 2);
		len += ft_puthex(va_arg(ap, unsigned long long), 'x');
	}
	else if (c == 'u')
		len = ft_put_unsigned(va_arg(ap, unsigned int));
	else if (c == '%')
		len = write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		len;
	int		i;

	va_start(ap, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				return (len);
			len += ft_formats(ap, s[i]);
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
