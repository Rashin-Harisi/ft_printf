/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:18:58 by rabdolho          #+#    #+#             */
/*   Updated: 2025/11/03 14:33:48 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdlib.h>

char	*pointer_hex_convert(unsigned long ptr)
{
	char			*hex;
	char			*result;
	unsigned long	number;
	int				count;

	hex = "0123456789abcdef";
	number = ptr;
	count = 0;
	while (number != 0)
	{
		number = number / 16;
		count++;
	}
	result = malloc((count + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[count] = '\0';
	while (count-- > 0)
	{
		result[count] = hex[ptr % 16];
		ptr = ptr / 16;
	}
	return (result);
}

static int	prt_handler(t_flags *flags, void *ptr, char **result)
{
	int	length;
	int	width;

	if (flags->plus)
		flags->space = 0;
	*result = pointer_hex_convert((unsigned long)ptr);
	length = ft_strlen(*result);
	if (flags->width > length)
		width = flags->width - length - 2;
	else
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


void	print_pointer(void *ptr, t_flags *flags, int *total_length)
{
	char	*result;
	int		width;

	if (ptr == NULL)
	{
		(*total_length) += ft_strlen("(nil)");
		return (ft_putstr_fd("(nil)", 1));
	}
	width = prt_handler(flags, ptr, &result);
	if (flags->minus == 0)
		not_minus_handler(flags, total_length, &width);
	if (flags->zero == 1 && flags->minus == 0)
	{
		ft_putstr_fd(result, 1);
		(*total_length) += ft_strlen(result);
	}
	else
	{
		if ( flags->minus)
			sign_check(flags, &width, total_length);
		ft_putstr_fd("0x", 1);
		(*total_length) += 2;
		ft_putstr_fd(result, 1);
		(*total_length) += ft_strlen(result);
	}
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
