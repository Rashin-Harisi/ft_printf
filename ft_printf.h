/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:39:40 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/22 19:07:19 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include "libft/libft.h"
# include <stdarg.h>


typedef struct	s_flags
{
	int	minus;
	int	zero;
	int	dot; //bolean to represent the precision defined or not.
	int	width;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}t_flags;

void    check_flags(t_flags *flags, char *str);
void	print_char(char c,t_flags *flags);
void    print_string(char *str, t_flags *flags);
void    print_pointer(void *ptr, t_flags *flags);

#endif
