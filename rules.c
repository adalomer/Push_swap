/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <adalomer60@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 03:37:49 by omadali           #+#    #+#             */
/*   Updated: 2025/01/30 03:37:50 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void ft_sa(t_stack **a)
{
    t_stack *top;
    t_stack *next;

    if (!a || !(*a) || !(*a)->next)
        return;
    top = *a;
    next = (*a)->next;
    top->next = next->next;
    next->next = top;
    *a = next;
    write(1, "sa\n", 3);
}

void ft_sb(t_stack **b)
{
    t_stack *top;
    t_stack *next;

    if (!b || !(*b) || !(*b)->next)
        return;
    top = *b;
    next = (*b)->next;
    top->next = next->next;
    next->next = top;
    *b = next;
    write(1, "sb\n", 3);
}

void ft_pa(t_stack **a, t_stack **b)
{
    t_stack *temp;

    if (!b || !(*b))
        return;
    temp = *b;
    *b = (*b)->next;
    temp->next = *a;
    *a = temp;
    write(1, "pa\n", 3);
}

void ft_pb(t_stack **a, t_stack **b)
{
    t_stack *temp;

    if (!a || !(*a))
        return;
    temp = *a;
    *a = (*a)->next;
    temp->next = *b;
    *b = temp;
    write(1, "pb\n", 3);
}