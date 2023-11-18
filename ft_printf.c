/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:42:33 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2023/11/19 00:28:57 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printformat(char thechar, va_list ap)
{
	int	count;

	count = 0;
	if (thechar == 'c')
		count += ft_retputchar(va_arg(ap, int));
	if (thechar == 's')
		count += ft_retputstr(va_arg(ap, char *));
	if (thechar == 'p')
	{
		count += write (1, "0x", 2);
		ft_retputnbr_hex((unsigned long)va_arg(ap, void *), &count, 'x');
	}
	if (thechar == 'd')
		ft_retputnbr(va_arg(ap, int), &count);
	if (thechar == 'i')
		ft_retputnbr(va_arg(ap, int), &count);
	if (thechar == 'u')
		ft_retputnbr_uint(va_arg(ap, unsigned int), &count);
	if (thechar == 'x' || thechar == 'X')
		ft_retputnbr_hex((unsigned int)va_arg(ap, int), &count, thechar);
	if (thechar == '%')
		count += write (1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			count += ft_printformat(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
