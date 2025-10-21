/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_hexdecimal_convert.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:43:44 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/21 14:10:12 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdlib.h>

/*
void binary_print(unsigned long n)
{
        int bits = sizeof(n)*8;
        for(int i = bits-1 ; i > 0; i--)
        {
                printf("%d",(int)((n >> i) & 1));
        }
}
*/

static void	initial_value(char *str, int *count)
{
	str[0] = '0';
	str[1] = 'x';
	str[*count + 1] = '\0';
}

char	*pointer_hex_convert(unsigned long ptr)
{
	char		*hex;
	char		*result;
	unsigned long	number;
	int		count;

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
