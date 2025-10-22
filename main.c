/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:53:33 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/22 18:18:41 by rabdolho         ###   ########.fr       */
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
			check_flags(&flags, str);
			switch(*str)
			{
				case 'c':
				{
					print_char(va_arg(args, int),&flags);
					break ;
				}
				case 's':
				{
					print_string(va_arg(args, char *),&flags);
					break ;
				}
				case 'p':
				{
					print_pointer(va_arg(args, void *), &flags);
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
