/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:18:58 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/24 14:00:46 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdlib.h>

static void	initial_value(char *str, int *count)
{
	str[0] = '0';
	str[1] = 'x';
	str[*count + 1] = '\0';
}

char	*pointer_hex_convert(unsigned long ptr)
{
	char			*hex;
	char			*result;
	unsigned long	number;
	int				count;

	hex = "0123456789abcdef";
	number = ptr;
	count = 1;
	while (number != 0)
	{
		number = number / 16;
		count++;
	}
	result = malloc((count + 1) * sizeof(char));
	if (!result)
		return (NULL);
	initial_value(result, &count);
	while (count > 1)
	{
		result[count] = hex[ptr % 16];
		ptr = ptr / 16;
		count--;
	}
	return (result);
}

static void	not_minus_handler(t_flags *flags, int *total_length, int *width)
{
	if (flags->zero == 1)
	{
		ft_putstr_fd("0x", 1);
		(*total_length) += 2;
	}
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

static void	minus_handler(int *width, int *total_length)
{
	while ((*width)--)
	{
		ft_putchar_fd(' ', 1);
		(*total_length)++;
	}
}

void	print_pointer(void *ptr, t_flags *flags, int *total_length)
{
	char	*result;
	int		length;
	int		width;

	result = pointer_hex_convert((unsigned long)ptr);
	length = ft_strlen(result);
	if (flags->width > length)
		width = flags->width - length;
	else
		width = 0;
	if (flags->minus == 0)
		not_minus_handler(flags, total_length, &width);
	if (flags->zero == 1)
	{
		ft_putstr_fd(&result[2], 1);
		(*total_length) += ft_strlen(result) - 2;
	}
	else
	{
		ft_putstr_fd(result, 1);
		(*total_length) += ft_strlen(result);
	}
	if (flags->minus == 1)
		minus_handler(&width, total_length);
	free(result);
}
