/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:35:44 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/23 20:03:23 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
void	print_unsigned(unsigned int n, t_flags *flags, int *total_length)
{
        int     width;
        char    *nbr;
        int     length;
        int     zero_precision;

        zero_precision = 0;
        nbr = ft_utoa(n);
        length = ft_strlen(nbr);
        if (flags->dot == 1)
                flags->zero = 0;
        if (flags->dot == 1 && flags->precision > length)
                zero_precision = flags->precision - length;
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
                        while (zero_precision-- > 0)
                        {
                                ft_putchar_fd('0', 1);
                                (*total_length)++;
                        }
                }
                else if (flags->zero)
                {
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
