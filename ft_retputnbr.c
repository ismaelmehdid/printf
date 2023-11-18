/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retputnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:33:13 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2023/11/18 23:55:27 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_retputnbr(int n, int *count)
{
	int const	save = n;
	char		temp;

	if (n == -2147483648)
	{
		*count += write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		*count += write (1, "-", 1);
		ft_retputnbr(-n, count);
	}
	else if (n <= 9 && n >= 0)
	{
		temp = n + '0';
		*count += write (1, &temp, 1);
	}
	else if (n > 9)
	{
		n = save / 10;
		ft_retputnbr(n, count);
		n = save % 10;
		ft_retputnbr(n, count);
	}
}
