/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_hexdecimal_convert.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:43:44 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/20 14:06:35 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void binary_print(unsigned long n)
{
        int bits = sizeof(n)*8;
        for(int i = bits-1 ; i > 0; i--)
        {
                printf("%d",(int)((n >> i) & 1));
        }
}

char *pointer_hex_convert(unsigned long ptr)
{
	char *hex = "123456789abcdef"
	char *result;
		
}
