/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <adalomer60@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:29:51 by omadali           #+#    #+#             */
/*   Updated: 2025/01/26 01:29:54 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void perform_radix_sort(t_stack **a, t_stack **b, int size)
{
    int max_bits = 0;
    int i = 0;
    int j;
    int num;

    while ((size - 1) >> max_bits)
        max_bits++;

    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            num = (*a)->index;
            if ((num >> i) & 1)
                ft_ra(a);
            else
                ft_pb(a, b);
            j++;
        }
        while (*b)
            ft_pa(a, b);
        i++;
    }
}

void ft_sort(t_stack **a, t_stack **b, int size)
{
    if (size <= 6)
    {
        ft_recursive_sort(a,b,size);
        return;
    }
    perform_radix_sort(a, b, size);
}






