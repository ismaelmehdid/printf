/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retputstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:30:02 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2023/11/19 00:20:23 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_retputstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}
