/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:42:33 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2023/11/19 19:49:26 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printformat(char thechar, va_list ap)
{
	int		count;
	void	*ptr;

	count = 0;
	if (thechar == 'c')
		count += ft_retputchar(va_arg(ap, int));
	else if (thechar == 's')
		count += ft_retputstr(va_arg(ap, char *));
	else if (thechar == 'p')
	{
		ptr = va_arg(ap, void *);
		if (ptr == NULL)
			return (count += write (1, "(nil)", 5));
		count += write (1, "0x", 2);
		ft_retputnbr_hex((unsigned long)ptr, &count, 'x');
	}
	else if (thechar == 'd' || thechar == 'i')
		ft_retputnbr(va_arg(ap, int), &count);
	else if (thechar == 'u')
		ft_retputnbr_uint(va_arg(ap, unsigned int), &count);
	else if (thechar == 'x' || thechar == 'X')
		ft_retputnbr_hex((unsigned int)va_arg(ap, int), &count, thechar);
	else if (thechar == '%')
		count += write (1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	ap;

	i = 0;
	count = 0;
	if (!format)
		return (0);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's'
				|| format[i + 1] == 'p' || format[i + 1] == 'd'
				|| format[i + 1] == 'i'
				|| format[i + 1] == 'u' || format[i + 1] == 'x'
				|| format[i + 1] == 'X' || format[i + 1] == '%'))
			count += ft_printformat(format[++i], ap);
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
