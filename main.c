/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:53:33 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/23 15:29:29 by rabdolho         ###   ########.fr       */
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
			check_flags(&flags, &str);
			switch(*str)
			{
				case 'c':
				{
					print_char(va_arg(args, int), &flags, &total_length );
					break ;
				}
				case 's':
				{
					print_string(va_arg(args, char *), &flags, &total_length);
					break ;
				}
				case 'p':
				{
					print_pointer(va_arg(args, void *), &flags , &total_length);
					break;
				}
				case 'd':
				case 'i':
				{
					print_decimal(va_arg(args, int), &flags, &total_length);
					break ; 
				}
				case 'u':
				{
					break ;
				}
				case 'x':
				{
					break ;
				}
				case 'X':
				{
					break ;
				}
				case '%':
				{
					ft_putchar_fd('%',1);
					break ;
				}
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
	printf("The original : |%5c| \n", c);
	ft_printf("My function : |%5c| \n", c);
	printf("---------------test string-------------------\n");
	char *test = "hello world";
	printf("The original : |%-7.3s| \n", test);
	ft_printf("My function : |%-7.3s| \n", test);
	printf("---------------test pointer-------------------\n");
        char *test_p = "hello world";
        printf("The original: |%020p| \n", test_p);
        ft_printf("My function : |%020p| \n", test_p);
	printf("---------------test-------------------\n");
	printf("the origin : |%-05d| \n" , -42);
	ft_printf("my finction : |%-05d| \n", -42);

	return 0;
}
