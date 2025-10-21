/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:53:33 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/21 18:53:06 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>


int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	total_length;
	t_flags	flags;

	total_length = 0;
	ft_memset(&flags, 0, sizeof(flags));
	va_start(args,str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			while (*str == '-' || *str == '0' || *str == '#' || *str == '+' || *str == ' '				)
			{
				if (*str == '-') flags.minus = 1;
				if (*str == '+') flags.plus = 1;
				if (*str == '#') flags.hash = 1;
				if (*str == '0') flags.zero = 1;
				if (*str == ' ') flags.space = 1;
				str++;
			}
			if (ft_isdigit(*str))
			{
				flags.width = ft_atoi(str);
				while (ft_isdigit(*str)) str++;
			}
			if (*str == '.')
			{
				flags.dot = 1;
				str++;
			}
			if (ft_isdigit(*str))
			{
				flags.precision = ft_atoi(str);
				while (ft_isdigit(*str)) str++;
			} else flags.precision = 0;
			switch(*str)
			{
				case 'c':
				{
					int c = va_arg(args, int);
					ft_putchar_fd(c, 1);
					break ;
				}
				case 's':
				{
					char *s = va_arg(args, char *);
					ft_putstr_fd(s, 1);
					break ;
				}
				case 'p':
				{
					void *ptr = va_arg(args, void *);
					char *result = pointer_hex_convert((unsigned long)ptr);
					ft_putstr_fd(result , 1);
					free(result);
					break;
				}
		/*
                case 'd':
                    float n = va_arg(args, float);
                    //char *deci_n = ft_deciconvert(n);
                    //ft_putstr_fd(deci_n , 1); 
                    break ;
                5case 'i':
                    int nbr = va_arg(args, int);
                    //char *nbr_chr = ft_atoi(nbr);
                    ft_putstr_fd(nbr_chr, 1);
                    break ;
                case 'u': 
                    float n = va_arg(args, float);
                    //char *deci_n = ft_deciconvert(n);
                    break ;
                case 'x': 
                    char *base = "0123456789abcdef";
                    int nbr_x = va_arg(args, int);
                    //char *nbr_base = ft_putnbr_base(nbr_x, base);
                    //ft_putstr_fd(nbr_base, 1);
                    
                case 'X':
                    char *base = "0123456789ABCDEF";
                    int nbr_x = va_arg(args, int);
                    //char *nbr_base = ft_putnbr_base(nbr_x, base);
                    //ft_putstr_fd(nbr_base, 1);
                    break ;
                case '%':
                    ft_putchr_fd('%',1);
                    break ;
		*/
            }
        }
        else if (*str == '\n')
            ft_putchar_fd('\n', 1);
        else
            ft_putchar_fd(*str, 1);
        str++;
        }
    va_end(args);
    return (total_length);
}


int main()
{
	printf("---------------test character-------------------\n");
	char c = 'C';
	printf("The original : %c \n", c);
	ft_printf("My function : %c \n", c);
	printf("---------------test string-------------------\n");
	char *test = "hello world";
	printf("The original : %s \n", test);
	ft_printf("My function : %s \n", test);
	printf("---------------test pointer-------------------\n");
        char *test_p = "hello world";
        printf("The original: %p \n", test_p);
        ft_printf("My function : %p \n", test_p);
	printf("---------------test-------------------\n");
	

	return 0;
}
