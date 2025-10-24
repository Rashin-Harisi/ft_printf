/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:31:20 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/24 11:50:57 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print_char(char c, t_flags *flags, int *total_length)
{
	int	width;

	if (flags->width > 1)
		width = flags->width - 1;
	else
		width = 0;
	if (flags->minus == 0)
	{
		while (width--)
		{
			ft_putchar_fd(' ', 1);
			(*total_length)++;
		}
	}
	ft_putchar_fd(c, 1);
	(*total_length)++;
	if (flags->minus == 1)
	{
		while (width--)
		{
			ft_putchar_fd(' ', 1);
			(*total_length)++;
		}
	}
}
