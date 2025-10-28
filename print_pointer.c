/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:18:58 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/28 21:31:52 by rabdolho         ###   ########.fr       */
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
	result = malloc((count + 3) * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '0';
	result[1] = 'x';
	result[count + 2] = '\0';
	while (count-- > 0)
	{
		result[count + 2] = hex[ptr % 16];
		ptr = ptr / 16;
	}
	return (result);
}

static int	prt_handler(t_flags *flags, void *ptr, char **result, char **pre)
{
	int	length;
	int	width;

	*pre = "0x";
	if (ptr == NULL)
	{
		*result = ft_strdup("(nil)");
		*pre = "";
	}
	else
		*result = pointer_hex_convert((unsigned long)ptr);
	length = ft_strlen(*result);
	if (flags->width > length)
		width = flags->width - length;
	else
		width = 0;
	return (width);
}

static void	not_minus_handler(t_flags *flags, int *total_length,
	int *width, char *pre)
{
	if (flags->zero == 1)
	{
		ft_putstr_fd(pre, 1);
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

static void	no_flags_minus(int *width, int *total_length)
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
	int		width;
	char	*pre;

	width = prt_handler(flags, ptr, &result, &pre);
	if (flags->minus == 0)
		not_minus_handler(flags, total_length, &width, pre);
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
		no_flags_minus(&width, total_length);
	free(result);
}
