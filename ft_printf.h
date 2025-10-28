/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:39:40 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/28 21:02:01 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot; //bolean to represent the precision defined or not.
	int	width;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

int		ft_printf(const char *str, ...);
void	check_flags(t_flags *flags, const char **str);
void	print_char(char c, t_flags *flags, int *total_length);
void	print_string(char *str, t_flags *flags, int *total_length);
void	print_pointer(void *ptr, t_flags *flags, int *total_length);
void	print_decimal(int n, t_flags *flags, int *total_length);
char	*sign_nbr_handler_decimal(char *sign, int n, t_flags *flags);
int		width_handler_decimal(t_flags *flags, int *zero_precision,
			int length, char sign);
void	sign_zero_handler_decimal(char sign, int *total_length,
			int *zero_precision);
void	no_flags_minus_decimal(t_flags *flags, int *width,
			int *total_length, char *sign);
void	yes_flags_minus_decimal(int *width, int *total_length);
char	*ft_utoa(unsigned int n);
void	print_unsigned(unsigned int n, t_flags *flags, int *total_length);
void	print_hex_small(unsigned int n, t_flags *flags, int *total_length);
void	print_hex_big(unsigned int n, t_flags *flags, int *total_length);
char	*hex_convert_big(unsigned int nbr);
char	*hex_convert_small(unsigned int nbr);
#endif
