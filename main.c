/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:35:09 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/28 21:35:20 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// int main() {
//     // Testing format specifiers with different types of arguments
//     char character = 'A';
//     char *string = "Hello, world!";
// 	char *string2 = NULL;
//     char *string3;
//     char  mina[10];
//     int integer = 42;
//     unsigned int unsigned_integer = 123;
//     void *pointer = (void *)0x12345678;
//     int a;
//     int b = 0;
//     int c = INT_MIN;
//     // Testing each format specifier
//     ft_printf("%d\n", b);
//     printf("%d\n\n", b);
    
//     ft_printf("%d\n", c);
//     printf("%d\n\n", c);

//     ft_printf("hello%s mina\n", mina);
//     printf("hello%s mina\n\n", mina);




//     printf("|%d|\n", ft_printf("Character: %c\n", character));
//     printf("|%d|\n", printf("Character: %c\n", character));
//     printf("|%d|\n", ft_printf("String: %s\n", string));
//     printf("|%d|\n", printf("String: %s\n", string));
//     printf("|%d|\n", ft_printf("String = NULL: %s\n", string2));
//     printf("|%d|\n", printf("String = NULL: %s\n", string2)); 
//     	int num_null_test2 = ft_printf("String = EMPTY: %s\n", string3);
//     	int num_null_main2 = printf("String = EMPTY: %s\n", string3);

//     printf("|%d|\n", ft_printf("just one persent:%\n"));
//     printf("|%d|\n", printf("just one persent:%\n"));
//     printf("|%d|\n", ft_printf("Percentage: %%\n"));
//     printf("|%d|\n", printf("Percentage: %%\n"));


//     printf("|%d|\n", ft_printf("Pointer: %p\n", pointer));
//     printf("|%d|\n", printf("Pointer: %p\n", pointer));
//     printf("|%d|\n", ft_printf("Decimal Integer: %d\n", integer));
//     printf("|%d|\n", printf("Decimal Integer: %d\n", integer));
//     printf("|%d|\n", ft_printf("Decimal Integer (unsigned): %u\n", unsigned_integer));
//     printf("|%d|\n", printf("Decimal Integer (unsigned): %u\n", unsigned_integer));
//     printf("|%d|\n", ft_printf("Hexadecimal Integer: %x\n", integer));
//     printf("|%d|\n", printf("Hexadecimal Integer: %x\n", integer));
//     printf("|%d|\n", ft_printf("Hexadecimal Integer (uppercase): %X\n", integer));
//     printf("|%d|\n", printf("Hexadecimal Integer (uppercase): %X\n", integer));
//     printf("|%d|\n", ft_printf("test:%d\n", a));
//     printf("|%d|\n", printf("main:%d\n", a));
//     printf("|%d|\n", ft_printf("print here the null\n"));
//     printf("|%d|\n", printf("print here the null\n"));
// 	int num_null_test = ft_printf(NULL);
// 	int num_null_main = printf(NULL);
//     printf("|%d|\n", ft_printf("test:%d\n", num_null_test));
//     printf("|%d|\n", printf("main:%d\n", num_null_main));

//     printf("|%d|\n", ft_printf("test:%d, %s, %c, %X\n", 1234, "testtest", 200, 8978));
//     printf("|%d|\n", printf("main:%d, %s, %c, %X\n", 1234, "testtest", 200, 8978));

//     return (0);
// }



#include <stdio.h>
#include <limits.h>

// Prototype for your ft_printf function
int ft_printf(const char *format, ...);

int main() {
    char character = 'A';
    char *string = "Hello, World!";
    char *null_string = NULL;
    int integer = 42;
    int negative_integer = -42;
    unsigned int unsigned_integer = 42;
    unsigned int large_unsigned_integer = UINT_MAX;
    void *pointer = &integer;

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


    return (0);
}
