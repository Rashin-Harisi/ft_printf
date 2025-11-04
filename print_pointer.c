/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:18:58 by rabdolho          #+#    #+#             */
/*   Updated: 2025/11/04 14:10:01 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdlib.h>

static int	prt_handler(t_flags *flags, void *ptr, char **result)
{
	int	length;
	int	width;

	if (flags->plus)
		flags->space = 0;
	*result = pointer_hex_convert((unsigned long)ptr);
	length = ft_strlen(*result);
	width = flags->width - length - 2;
	if (width < 0)
		width = 0;
	if (flags->plus || flags->space)
		width++;
	return (width);
}

static void	sign_check(t_flags *flags, int *width, int *total_length)
{
	if (flags->plus && (*width) > 0)
	{
		(*width)--;
		ft_putchar_fd('+', 1);
		(*total_length)++;
	}
	else if (flags->space && (*width) > 0)
	{
		(*width)--;
		ft_putchar_fd(' ', 1);
		(*total_length)++;
	}
	if (flags->zero == 1)
	{
		ft_putstr_fd("0x", 1);
		(*total_length) += 2;
	}
}

static void	not_minus_handler(t_flags *flags, int *total_length,
	int *width)
{
	sign_check(flags, width, total_length);
	while ((*width)--)
	{
		if (flags->zero == 1)
		{
			ft_putchar_fd('0', 1);
			(*total_length)++;
		}
		else
		{
			ft_putchar_fd(' ', 1);
			(*total_length)++;
		}
	}
}

static void	print_handler(t_flags *flags, int *width,
	int *total_length, char *result)
{
	if (flags->zero == 1 && flags->minus == 0)
	{
		ft_putstr_fd(result, 1);
		(*total_length) += ft_strlen(result);
	}
	else
	{
		if (flags->minus)
			sign_check(flags, width, total_length);
		ft_putstr_fd("0x", 1);
		(*total_length) += 2;
		ft_putstr_fd(result, 1);
		(*total_length) += ft_strlen(result);
	}
}

void	print_pointer(void *ptr, t_flags *flags, int *total_length)
{
	char	*result;
	int		width;

	if (ptr == NULL)
		return (print_string("(nil)", flags, total_length));
	width = prt_handler(flags, ptr, &result);
	if (flags->minus == 0)
		not_minus_handler(flags, total_length, &width);
	print_handler(flags, &width, total_length, result);
	if (flags->minus == 1)
	{
		while (width--)
		{
			ft_putchar_fd(' ', 1);
			(*total_length)++;
		}
	}
	free(result);
}
