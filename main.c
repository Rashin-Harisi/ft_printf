/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:53:33 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/20 22:05:38 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>


int ft_printf(const char *str, ...)
{
    va_list args;
    int total_length = 0;
    va_start(args,str);
    
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            //check_flags(str);
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
	             //printf("%ld %ld\n", sizeof((unsigned long)ptr), (unsigned long)ptr);
		     pointer_hex_convert((unsigned long)ptr);
		     //ft_putstr_fd(result , 1);
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
		char *test = "hello world";
		ft_printf("the result is %p\n", test);
		printf("the origin : %p \n", test);
		return 0;
}
