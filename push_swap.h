/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <adalomer60@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:08:31 by omadali           #+#    #+#             */
/*   Updated: 2025/01/30 03:38:42 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_stack {
    int data;
    int index;
    struct s_stack* next;
} t_stack;

int     ft_atoi(const char *str);
int     ft_lstsize(t_stack *lst);
int     ft_is_sorted(t_stack *a);
void    ft_error(t_stack **head);
void    ft_index(t_stack **head);
void    ft_checkrepeat(t_stack **head);
int    ft_createnode(t_stack **a, int value);
void	ft_clear(t_stack **a, t_stack **b);
char	**ft_split(char const *s, char c);
void    ft_sa(t_stack **a);
void    ft_sb(t_stack **b);
void    ft_pa(t_stack **a, t_stack **b);
void    ft_pb(t_stack **a, t_stack **b);
void    ft_ra(t_stack **a);
void    ft_rb(t_stack **b);
void    ft_rra(t_stack **a);
void    ft_rrb(t_stack **b);
void ft_sort(t_stack **a, t_stack **b, int size);
void sort_three(t_stack **a);
void sort_small(t_stack **a, t_stack **b,int size);
int pivotfinder(t_stack **a, int len);
void ft_recursive_sort(t_stack **a, t_stack **b, int len);
int ft_insertion(int *temp_array, int len);
void sort_threeb(t_stack **b);
void	sort_check(t_stack **a, t_stack **b);
int argcontrol(char **str, t_stack **a, t_stack **b);

#endif