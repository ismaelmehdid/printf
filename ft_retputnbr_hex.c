/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retputnbr_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:34:30 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2023/11/19 16:16:59 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_retputnbr_hex(unsigned long n, int *count, char thechar)
{
	char	*baseup;
	char	*baselow;

	baseup = "0123456789ABCDEF";
	baselow = "0123456789abcdef";
	if (n < 16)
	{
		if (thechar == 'X')
			*count += write (1, &baseup[n], 1);
		else if (thechar == 'x')
			*count += write (1, &baselow[n], 1);
	}
	else
	{
		ft_retputnbr_hex(n / 16, count, thechar);
		ft_retputnbr_hex(n % 16, count, thechar);
	}
}
