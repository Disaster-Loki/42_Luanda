/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:06:14 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/19 18:15:51 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h" 

void test_char() {
    char c = 'A';
    printf("Test char:\n");
    printf("printf: |%c|\n", c);
    ft_printf("ft_printf: |%c|\n", c);
}

void test_string() {
    char *str = "Hello, World!";
    printf("Test string:\n");
    printf("printf: |%s|\n", str);
    ft_printf("ft_printf: |%s|\n", str);
}

void test_pointer() {
    char *str = "Hello, World!";
    void *ptr = (void *)str;
    printf("Test pointer:\n");
    printf("printf: |%p|\n", ptr);
    ft_printf("ft_printf: |%p|\n", ptr);
    printf("\n");
}

void test_int() {
    int n = 42;
    printf("Test int:\n");
    printf("printf: |%d|\n", n);
    ft_printf("ft_printf: |%d|\n", n);
}

void test_unsigned() {
    unsigned int n = 42;
    printf("Test unsigned int:\n");
    printf("printf: |%u|\n", n);
    ft_printf("ft_printf: |%u|\n", n);
}

void test_hex() {
    unsigned int n = 42;
    printf("Test hex (lowercase):\n");
    printf("printf: |%x|\n", n);
    ft_printf("ft_printf: |%x|\n", n);

    printf("Test hex (uppercase):\n");
    printf("printf: |%X|\n", n);
    ft_printf("ft_printf: |%X|\n", n);
}

void test_mixed() {
    char c = 'A';
    char *str = "Hello";
    int n = 42;
    unsigned int u = 42;
    void *ptr = str;

    printf("Test mixed:\n");
    printf("printf: |Char: %c, String: %s, Pointer: %p, Int: %d, Unsigned: %u, Hex: %x|\n", c, str, ptr, n, u, n);
    ft_printf("ft_printf: |Char: %c, String: %s, Pointer: %p, Int: %d, Unsigned: %u, Hex: %x|\n", c, str, ptr, n, u, n);
}

int main(void) {
    test_char();
    test_string();
    test_pointer();
    test_int();
    test_unsigned();
    test_hex();
    test_mixed();
    return 0;
}