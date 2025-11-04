/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:54:59 by rabdolho          #+#    #+#             */
/*   Updated: 2025/11/04 12:54:26 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	null_print_handler(char **str, t_flags *flags, int *length)
{
	*str = "(null)";
	if (flags->precision < 6)
		*length = 0;
}

static void	flags_minus(int *width, int *total_length)
{
	while ((*width)--)
	{
		ft_putchar_fd(' ', 1);
		(*total_length)++;
	}
}

void	print_string(char *str, t_flags *flags, int *total_length)
{
	int	width;
	int	length;
	int	i;

	i = 0;
	if (!str)
		null_print_handler(&str, flags, &length);
	else
		length = ft_strlen(str);
	if (flags->dot == 1 && (flags->precision < length))
		length = flags->precision;
	if (flags->width > length)
		width = flags->width - length;
	else
		width = 0;
	if (flags->minus == 0)
		flags_minus(&width, total_length);
	while (i < length)
	{
		ft_putchar_fd(str[i++], 1);
		(*total_length)++;
	}
	if (flags->minus == 1)
		flags_minus(&width, total_length);
}
