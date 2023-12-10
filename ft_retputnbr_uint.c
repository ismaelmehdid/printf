/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retputnbr_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:35:07 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2023/11/19 00:29:21 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_retputnbr_uint(unsigned int n, int *count)
{
	unsigned int const	save = n;
	char				temp;

	if (n <= 9)
	{
		temp = n + '0';
		*count += write (1, &temp, 1);
	}
	else if (n > 9)
	{
		n = save / 10;
		ft_retputnbr_uint(n, count);
		n = save % 10;
		ft_retputnbr_uint(n, count);
	}
}
