/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:44:19 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2023/11/19 00:09:32 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

int		ft_retputchar(const char thechar);

int		ft_retputstr(const char *str);

void	ft_retputnbr_hex(unsigned long n, int *count, char thechar);

void	ft_retputnbr_uint(unsigned int n, int *count);

void	ft_retputnbr(int n, int *count);

#endif