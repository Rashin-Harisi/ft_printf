/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:00:27 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/27 14:19:24 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static char	*hex_convert(unsigned int nbr)
{
	char			*hex;
	char			*result;
	unsigned long	number;
	int				count;

	hex = "0123456789abcdef";
	number = nbr;
	count = 1;
	while (number != 0)
	{
		number = number / 16;
		count++;
	}
	result = malloc((count + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[count] = '\0';
	while (count > 0)
	{
		result[--count] = hex[nbr % 16];
		nbr = nbr / 16;
	}
	return (result);
}

static int	width_hash_handler(t_flags *flags, int *length,
	int *zero_precision, int *hash)
{
	int	width;

	width = 0;
	if (flags->hash == 1)
		*hash = 1;
	if (flags->dot == 1)
		flags->zero = 0;
	if (flags->dot == 1 && flags->precision > (*length))
		*zero_precision = flags->precision - (*length);
	if (flags->hash == 1)
		width = flags->width - (*length) - (*zero_precision) - 2;
	else
		width = flags->width - (*length) - (*zero_precision);
	if (width < 0)
		width = 0;
	return (width);
}

static void	no_flags_minus(t_flags *flags, int *hash,
	int *total_length, int *width)
{
	char	c;

	if (flags->dot || !flags->zero)
		c = ' ';
	else
	{
		if (*hash)
		{
			ft_putstr_fd("0x", 1);
			(*total_length) += 2;
			*hash = 0;
		}
		c = '0';
	}
	while ((*width)--)
	{
		ft_putchar_fd(c, 1);
		(*total_length)++;
	}
}

static void	hash_zero_handler(int *hash, int *total_length, int *zero_precision)
{
	if (*hash)
	{
		ft_putstr_fd("0x", 1);
		(*total_length) += 2;
	}
	while ((*zero_precision)-- > 0)
	{
		ft_putchar_fd('0', 1);
		(*total_length)++;
	}
}

void	print_hex_small(unsigned int n, t_flags *flags, int *total_length)
{
	int		width;
	char	*nbr;
	int		length;
	int		zero_precision;
	int		hash;

	hash = 0;
	zero_precision = 0;
	nbr = hex_convert(n);
	length = ft_strlen(nbr);
	width = width_hash_handler(flags, &length, &zero_precision, &hash);
	if (flags->minus == 0)
		no_flags_minus(flags, &hash, total_length, &width);
	hash_zero_handler(&hash, total_length, &zero_precision);
	write(1, nbr, length);
	(*total_length) += length;
	if (flags->minus == 1)
	{
		while (width--)
		{
			ft_putchar_fd(' ', 1);
			(*total_length)++;
		}
	}
	free(nbr);
}
