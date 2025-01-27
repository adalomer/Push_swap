/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <adalomer60@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:36:10 by omadali           #+#    #+#             */
/*   Updated: 2025/01/26 01:37:34 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void ft_createnode(t_stack **a, int value) 
{
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    if (new_node == NULL)
	{
        write(2,"error",6);
        return;
    }

    new_node->data = value;
    new_node->next = NULL;

    if (*a == NULL) 
    {
        new_node->next = NULL;
        *a = new_node;
    } 
    else 
    {
        t_stack *current = *a;
        while (current->next != NULL)
            current = current->next;

        current->next = new_node;
    }
}

void	ft_clear(t_stack **a, t_stack **b)
{
	while ((*a)) 
	{
        t_stack *temp = (*a);
        (*a) = (*a)->next;
        free(temp);
    }
	while ((*b)) {
        t_stack *temp = (*b);
        (*b) = (*b)->next;
        free(temp);
    }
}
int main(int argc, char **argv)
{
    int     i;
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    i = 1;
    if (argc < 2)
        return (1);
    while (i < argc)
        ft_createnode(&a, ft_atoi(argv[i++]));

    if (ft_is_sorted(a))
        return (0);
    ft_checkrepeat(&a);
    ft_index(&a);
	ft_sort(&a,&b,ft_lstsize(a));
    ft_clear(&a,&b);
    return (0);
}
