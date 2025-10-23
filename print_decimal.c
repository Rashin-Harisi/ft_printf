/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:00:30 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/23 15:28:55 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char	*sign_nbr_handler(char *sign,int n, t_flags *flags)
{
	long long	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr = -(long long)n;
		*sign = '-';
	}
	else if (flags->plus == 1)
		*sign = '+';
	else if (flags->space == 1)
		*sign = ' ';
	return (ft_itoa(nbr));
}


void	print_decimal(int n, t_flags *flags, int *total_length)
{
	int	width;
	char	*nbr;
	int	length;
	char	sign;
	int	zero_precision;

	sign = 0;
	zero_precision = 0;
	nbr = sign_nbr_handler(&sign, n, flags);
	length = ft_strlen(nbr);
	if (flags->dot == 1)
		flags->zero = 0;
	if (flags->dot == 1 && flags->precision > length)
		zero_precision = flags->precision - length;
	if (sign)
		width = flags->width - length - zero_precision - 1;
	else
		width = flags->width - length - zero_precision;
	if (width < 0)
		width = 0;
	if (flags->minus == 0)
	{
		if (flags->dot)
		{
			while(width--)
                	{
                        	ft_putchar_fd(' ', 1);
                        	(*total_length)++;
                	}
			if (sign)
			{
				ft_putchar_fd(sign, 1);
				(*total_length)++;
				sign = 0;
			}
			while (zero_precision-- > 0)
                        {
                                ft_putchar_fd('0', 1);
                                (*total_length)++;
                        }
		}
		else if (flags->zero)
		{
			if (sign)
                        {
                                ft_putchar_fd(sign, 1);
                                (*total_length)++;
                                sign = 0;
                        }
			while (width--)
			{
				ft_putchar_fd('0', 1);
				(*total_length)++;
			}
		}
		else
		{
			while(width--)
			{
				ft_putchar_fd(' ', 1);
				(*total_length)++;
			}
		}
	}
	if (sign)
	{
		ft_putchar_fd(sign, 1);
		(*total_length)++;
	}
	while (zero_precision-- > 0)
	{
		ft_putchar_fd('0', 1);
		(*total_length)++;
	}
	
	write(1, nbr, length);
	(*total_length) += length;
	if ( flags->minus == 1)
	{
		while (width--)
		{
			ft_putchar_fd(' ', 1);
			(*total_length)++;
		}
	}
	free(nbr);
}
