/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:41:51 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/31 17:26:06 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int ret1, ret2;
    int a = 42;
    void *ptr = &a;
    char character = 'A';
    char *string = "Hello, World!";
    char *null_string = NULL;
    int integer = 42;
    int negative_integer = -42;
    unsigned int unsigned_integer = 42;
    unsigned int large_unsigned_integer = UINT_MAX;
    void *pointer = &integer;

    printf("\n===================== Simple test ============================\n");
    // Character
    printf("|%d|\n", ft_printf("Character: %c\n", character));
    printf("|%d|\n", printf("Character: %c\n", character));

    // String
    printf("|%d|\n", ft_printf("String: %s\n", string));
    printf("|%d|\n", printf("String: %s\n", string));
    
    // Null string
    printf("|%d|\n", ft_printf("Null String: %s\n", null_string));
    printf("|%d|\n", printf("Null String: %s\n", null_string));
    
    // Integer
    printf("|%d|\n", ft_printf("Integer: %d\n", integer));
    printf("|%d|\n", printf("Integer: %d\n", integer));

    // Negative integer
    printf("|%d|\n", ft_printf("Negative Integer: %d\n", negative_integer));
    printf("|%d|\n", printf("Negative Integer: %d\n", negative_integer));

    // Unsigned integer
    printf("|%d|\n", ft_printf("Unsigned Integer: %u\n", unsigned_integer));
    printf("|%d|\n", printf("Unsigned Integer: %u\n", unsigned_integer));

    // Large unsigned integer
    printf("|%d|\n", ft_printf("Large Unsigned Integer: %u\n", large_unsigned_integer));
    printf("|%d|\n", printf("Large Unsigned Integer: %u\n", large_unsigned_integer));

    // Hexadecimal (lowercase)
    printf("|%d|\n", ft_printf("Hexadecimal (lowercase): %x\n", unsigned_integer));
    printf("|%d|\n", printf("Hexadecimal (lowercase): %x\n", unsigned_integer));

    // Hexadecimal (uppercase)
    printf("|%d|\n", ft_printf("Hexadecimal (uppercase): %X\n", unsigned_integer));
    printf("|%d|\n", printf("Hexadecimal (uppercase): %X\n", unsigned_integer));

    // Pointer
    printf("|%d|\n", ft_printf("Pointer: %p\n", pointer));
    printf("|%d|\n", printf("Pointer: %p\n", pointer));

    // Percent sign
    printf("|%d|\n", ft_printf("Percent Sign: %%\n"));
    printf("|%d|\n", printf("Percent Sign: %%\n"));

    printf("|%d|\n", ft_printf("Percent Sign one: %\n"));
    printf("|%d|\n", printf("Percent Sign one: %\n"));
    
    printf("|%d|\n", ft_printf("%\n"));
    printf("|%d|\n", printf("%\n"));

    printf("\n====================================== complecated test ==================\n");
    printf("\n===================== BASIC FUNCTIONALITY =====================\n");
    ret1 = ft_printf("Hello %s %d!\n", "Rashin", 2025);
    ret2 = printf("Hello %s %d!\n", "Rashin", 2025);
    printf("ft:%d | sys:%d\n\n", ret1, ret2);

    printf("===================== FLAGS COMBINATIONS =====================\n");

    printf("\n-- ZERO & WIDTH --\n");
    ret1 = ft_printf("|%010d| |%010i| |%010u| |%010x| |%010X|\n", 42, -42, 42u, 42, 42);
    ret2 = printf("|%010d| |%010i| |%010u| |%010x| |%010X|\n", 42, -42, 42u, 42, 42);
    printf("ft:%d | sys:%d\n\n", ret1, ret2);

    printf("\n-- LEFT ALIGN ( - ) --\n");
    ret1 = ft_printf("|%-10d| |%-10i| |%-10s| |%-10x|\n", 42, -42, "Hi", 42);
    ret2 = printf("|%-10d| |%-10i| |%-10s| |%-10x|\n", 42, -42, "Hi", 42);
    printf("ft:%d | sys:%d\n\n", ret1, ret2);

    printf("\n-- PLUS ( + ) and SPACE --\n");
    ret1 = ft_printf("|%+d| |% d| |%+i| |% i|\n", 42, 42, -42, -42);
    ret2 = printf("|%+d| |% d| |%+i| |% i|\n", 42, 42, -42, -42);
    printf("ft:%d | sys:%d\n\n", ret1, ret2);

    printf("\n-- HASH (#) FLAG --\n");
    ret1 = ft_printf("|%#x| |%#X| |%#8x| |%#08x| |%#x|\n", 0, 0, 42, 42, UINT_MAX);
    ret2 = printf("|%#x| |%#X| |%#8x| |%#08x| |%#x|\n", 0, 0, 42, 42, UINT_MAX);
    printf("ft:%d | sys:%d\n\n", ret1, ret2);

    printf("\n-- COMBINED FLAGS --\n");
    ret1 = ft_printf("|%#-10x| |%0#10x| |%#010x| |%#-010x|\n", 255, 255, 255, 255);
    ret2 = printf("|%#-10x| |%0#10x| |%#010x| |%#-010x|\n", 255, 255, 255, 255);
    printf("ft:%d | sys:%d\n\n", ret1, ret2);

    printf("\n-- WIDTH + PRECISION --\n");
    ret1 = ft_printf("|%10.5d| |%10.5i| |%10.5u| |%10.5x| |%10.5X|\n", 42, -42, 42, 42, 42);
    ret2 = printf("|%10.5d| |%10.5i| |%10.5u| |%10.5x| |%10.5X|\n", 42, -42, 42, 42, 42);
    printf("ft:%d | sys:%d\n\n", ret1, ret2);
    
    printf("\n-- ZERO + PRECISION (should ignore zero flag) --\n");
    ret1 = ft_printf("|%010.5d| |%010.5i| |%010.5u| |%010.5x|\n", 42, -42, 42, 42);
    ret2 = printf("|%010.5d| |%010.5i| |%010.5u| |%010.5x|\n", 42, -42, 42, 42);
    printf("ft:%d | sys:%d\n\n", ret1, ret2);

    printf("\n-- COMBINATION OF FLAGS + WIDTH + PRECISION --\n");
    ret1 = ft_printf("|%#+10.5x| |% -10.5d| |%0+10.5i| |%-+10.5d|\n", 255, 255, 255, -255);
    ret2 = printf("|%#+10.5x| |% -10.5d| |%0+10.5i| |%-+10.5d|\n", 255, 255, 255, -255);
    printf("ft:%d | sys:%d\n\n", ret1, ret2);

    printf("\n===================== POINTER & STRING =====================\n");
    ret1 = ft_printf("Pointer: %p | NULL: %p | Wide: %20p\n", ptr, NULL, ptr);
    ret2 = printf("Pointer: %p | NULL: %p | Wide: %20p\n", ptr, NULL, ptr);
    printf("ft:%d | sys:%d\n\n", ret1, ret2);

    ret1 = ft_printf("String: |%.5s| |%10.3s| |%-10.4s|\n", "HelloWorld", "Test", "C");
    ret2 = printf("String: |%.5s| |%10.3s| |%-10.4s|\n", "HelloWorld", "Test", "C");
    printf("ft:%d | sys:%d\n\n", ret1, ret2);

    printf("\n===================== INVALID / IGNORED FLAGS =====================\n");

    ret1 = ft_printf("Invalid flag on string: |%#s| |%0s| |%+s|\n", "Hi", "There", "World");
    ret2 = printf("Invalid flag on string: |%#s| |%0s| |%+s|\n", "Hi", "There", "World");
    printf("ft:%d | sys:%d\n\n", ret1, ret2);

    ret1 = ft_printf("Invalid flag on char: |%#c| |%0c| |%+c|\n", 'A', 'B', 'C');
    ret2 = printf("Invalid flag on char: |%#c| |%0c| |%+c|\n", 'A', 'B', 'C');
    printf("ft:%d | sys:%d\n\n", ret1, ret2);

    ret1 = ft_printf("Invalid flag on pointer: |%+p| |%0p| |% p|\n", ptr, ptr, ptr);
    ret2 = printf("Invalid flag on pointer: |%+p| |%0p| |% p|\n", ptr, ptr, ptr);
    printf("ft:%d | sys:%d\n\n", ret1, ret2);

    printf("\n===================== EXTREME VALUES =====================\n");
    ret1 = ft_printf("INT_MIN: %d | INT_MAX: %d | UINT_MAX: %u\n", INT_MIN, INT_MAX, UINT_MAX);
    ret2 = printf("INT_MIN: %d | INT_MAX: %d | UINT_MAX: %u\n", INT_MIN, INT_MAX, UINT_MAX);
    printf("ft:%d | sys:%d\n\n", ret1, ret2);

    ret1 = ft_printf("Zero precision with zero value: |%.0d| |%.0x| |%.0u|\n", 0, 0, 0);
    ret2 = printf("Zero precision with zero value: |%.0d| |%.0x| |%.0u|\n", 0, 0, 0);
    printf("ft:%d | sys:%d\n\n", ret1, ret2);

    ret1 = ft_printf("Long width + precision: |%50.40d|\n", 123456);
    ret2 = printf("Long width + precision: |%50.40d|\n", 123456);
    printf("ft:%d | sys:%d\n\n", ret1, ret2);

    printf("\n===================== MIXED FORMATTING =====================\n");
    ret1 = ft_printf("Mix: %s %d %#x %+i %u %p %%\n", "Rashin", -42, 255, 42, 300u, ptr);
    ret2 = printf("Mix: %s %d %#x %+i %u %p %%\n", "Rashin", -42, 255, 42, 300u, ptr);
    printf("ft:%d | sys:%d\n\n", ret1, ret2);


	ft_printf("my test |%010u|\n", 42u);
    return (0);
}
