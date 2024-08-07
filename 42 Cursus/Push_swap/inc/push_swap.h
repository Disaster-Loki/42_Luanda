/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:00:31 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/31 16:00:34 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct stack
{
	int				content;
	int				index;
	struct stack	*next;
	struct stack	*prev;
}	t_stack;
//Operactions
//swap
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **a, t_stack **b);
//rotate
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rotate(t_stack **stack);
void	rr(t_stack **a, t_stack **b);
//reverse
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	reverse(t_stack **stack);
void	rrr(t_stack **a, t_stack **b);
//push
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
// Error handlers
int		is_valid_integer(char *s);
int		ft_isdigit_string(char *s);
int		has_duplicates(char **args);
int		error_handler(int av, char **args);
// Indexing
void	get_index(t_stack **stack);
//List handlers
int		lst_size(t_stack *stack);
t_stack	*ft_lst_new(int content);
t_stack	*ft_lst_last(t_stack *stack);
void	ft_lst_addback(t_stack **stack, t_stack *news);
void	ft_lst_addfront(t_stack **stack, t_stack *news);
// Stack Init and clear
void	clear_stack(t_stack **stack);
int		init_stack(int av, char **args, t_stack **stack_a);
// stack_utils
void	reset_index(t_stack **stack);
int		check_sorted(t_stack **stack);
int		find_min_pos(t_stack **stack);
//int		sorted_to_top(t_stack **stack, int size);
void	move_min_to_top(t_stack **stack, int size);
// Sorting Algorithm
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	simple_sort(t_stack **stack_a, t_stack **stack_b);
// utils
void	ft_putnbr(int n);
int		ft_atoi(char *str);
int		ft_isdigit(char c);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	free_split(char **split);
int		ft_toklen(char *str, char c);
char	**ft_split(char *str, char c);
void	ft_putstr(char	*str);
int		ft_strlcpy(char *dst, char *src, int size);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
