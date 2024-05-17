/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:10:38 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/17 17:07:25 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct  s_list
{
    void    *content;
    struct s_list  *next; 
}   t_list;

// Libc functions
int	    ft_tolower(int c);
int	    ft_toupper(int u);
int	    ft_isprint(int c);
int	    ft_isalnum(int k);
int	    ft_isalpha(char c);
int	    ft_isascii(int num);
int	    ft_isdigit(int num);
int	    ft_atoi(const char *str);
int	    ft_strncmp(char *s1, char *s2, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strchr(const char *s, int n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	ft_bzero(void *s, size_t n);
void    *ft_memchr(const void *s, int c, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);

// Additional functions
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);

// Bonus

#endif