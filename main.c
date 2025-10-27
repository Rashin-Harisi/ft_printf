/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:38:02 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/27 18:38:09 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int ret_printf, ret_ft;
    char c = 'A';
    char *s = "Hello, world!";
    char *null_s = NULL;
    int d = 42;
    int neg = -42;
    int zero = 0;
    unsigned int u = 4294967295U; // UINT_MAX
    void *p = &d;
    void *null_p = NULL;

    printf("========== CHARACTER TESTS ==========\n");
    ret_ft = ft_printf("ft : |%c|\n", c);
    ret_printf = printf("sys: |%c|\n\n", c);
    printf("return(ft/sys): %d / %d\n\n", ret_ft, ret_printf);

    printf("========== STRING TESTS ==========\n");
    ret_ft = ft_printf("ft : |%s|\n", s);
    ret_printf = printf("sys: |%s|\n\n", s);
    printf("return(ft/sys): %d / %d\n\n", ret_ft, ret_printf);

    ret_ft = ft_printf("ft : |%s|\n", null_s);
    ret_printf = printf("sys: |%s|\n\n", null_s);
    printf("return(ft/sys): %d / %d\n\n", ret_ft, ret_printf);

    ret_ft = ft_printf("ft : |%s|\n", "");
    ret_printf = printf("sys: |%s|\n\n", "");
    printf("return(ft/sys): %d / %d\n\n", ret_ft, ret_printf);

    printf("========== POINTER TESTS ==========\n");
    ret_ft = ft_printf("ft : |%p|\n", p);
    ret_printf = printf("sys: |%p|\n\n", p);
    printf("return(ft/sys): %d / %d\n\n", ret_ft, ret_printf);

    ret_ft = ft_printf("ft : |%p|\n", null_p);
    ret_printf = printf("sys: |%p|\n\n", null_p);
    printf("return(ft/sys): %d / %d\n\n", ret_ft, ret_printf);

    printf("========== DECIMAL / INTEGER TESTS ==========\n");
    ret_ft = ft_printf("ft : |%d| |%i| |%d|\n", d, neg, zero);
    ret_printf = printf("sys: |%d| |%i| |%d|\n\n", d, neg, zero);
    printf("return(ft/sys): %d / %d\n\n", ret_ft, ret_printf);

    ret_ft = ft_printf("ft : |%d| |%d|\n", INT_MAX, INT_MIN);
    ret_printf = printf("sys: |%d| |%d|\n\n", INT_MAX, INT_MIN);
    printf("return(ft/sys): %d / %d\n\n", ret_ft, ret_printf);

    printf("========== UNSIGNED TESTS ==========\n");
    ret_ft = ft_printf("ft : |%u| |%u| |%u|\n", u, zero, 1);
    ret_printf = printf("sys: |%u| |%u| |%u|\n\n", u, zero, 1);
    printf("return(ft/sys): %d / %d\n\n", ret_ft, ret_printf);

    printf("========== HEXADECIMAL TESTS ==========\n");
    ret_ft = ft_printf("ft : |%x| |%X|\n", u, u);
    ret_printf = printf("sys: |%x| |%X|\n\n", u, u);
    printf("return(ft/sys): %d / %d\n\n", ret_ft, ret_printf);

    ret_ft = ft_printf("ft : |%x| |%X|\n", zero, 255);
    ret_printf = printf("sys: |%x| |%X|\n\n", zero, 255);
    printf("return(ft/sys): %d / %d\n\n", ret_ft, ret_printf);

    printf("========== PERCENT SIGN TESTS ==========\n");
    ret_ft = ft_printf("ft : |%%|\n");
    ret_printf = printf("sys: |%%|\n\n");
    printf("return(ft/sys): %d / %d\n\n", ret_ft, ret_printf);

    printf("========== MIXED TESTS ==========\n");
    ret_ft = ft_printf("ft : Char:%c Str:%s Ptr:%p Dec:%d Int:%i Uns:%u Hex:%x HEX:%X %%\n",
        c, s, p, d, neg, u, u, u);
    ret_printf = printf("sys: Char:%c Str:%s Ptr:%p Dec:%d Int:%i Uns:%u Hex:%x HEX:%X %%\n\n",
        c, s, p, d, neg, u, u, u);
    printf("return(ft/sys): %d / %d\n\n", ret_ft, ret_printf);

    printf("========== LENGTH / STRESS TESTS ==========\n");
    char long_str[1024];
    for (int i = 0; i < 1023; i++)
        long_str[i] = 'A' + (i % 26);
    long_str[1023] = '\0';
    ret_ft = ft_printf("ft : %s\n", long_str);
    ret_printf = printf("sys: %s\n\n", long_str);
    printf("return(ft/sys): %d / %d\n\n", ret_ft, ret_printf);

    printf("========== NULL FORMAT TEST (should handle gracefully) ==========\n");
    ret_ft = ft_printf(NULL);
    ret_printf = printf(NULL); // Undefined, but to compare
    printf("return(ft/sys): %d / %d\n", ret_ft, ret_printf);

    return 0;
}

