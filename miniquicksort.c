/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniquicksort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 03:38:00 by omadali           #+#    #+#             */
/*   Updated: 2025/01/30 23:37:04 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int ft_insertion(int *temp_array, int len)
{
    int i;
    int key;
    int j;
    int pivot;

    i = 1;
    while (i < len)
    {
        key = temp_array[i];
        j = i - 1;
        while (j >= 0 && temp_array[j] > key)
        {
            temp_array[j + 1] = temp_array[j];
            j--;
        }
        temp_array[j + 1] = key;
        i++;
    }
    pivot = temp_array[len / 2];
    free(temp_array);
    return (pivot);
}

int pivotfinder(t_stack **a, int len)
{
    int *temp_array;
    int i;
    t_stack *temp;

    i = 0;
    temp_array = (int *)malloc(sizeof(int) * len);
    if (!temp_array)
        ft_error(a);
    temp = *a;
    while (i < len)
    {
        temp_array[i] = temp->index;
        temp = temp->next;
        i++;
    }
    return (ft_insertion(temp_array, len));
}
void ft_recursive_sort(t_stack **a, t_stack **b, int len)
{
    int pb_count = 0;
    int i = 0;
    int pivot;

    pivot = pivotfinder(a, len);
    int push_c = len / 2;

    while (i < len && push_c)
    {
        if ((*a)->index < pivot && push_c--)
        {
            ft_pb(a, b);
            pb_count++;
        }
        else 
        	ft_ra(a);
        i++;
    }
	sort_check(a,b);
    while (pb_count--) 
        ft_pa(a, b);

}
void	sort_check(t_stack **a, t_stack **b)
{
	if(ft_lstsize(*a) == 2 && (*a)->index > (*a)->next->index)
		ft_sa(a);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	if(ft_lstsize(*b) == 2 && (*b)->index < (*b)->next->index)
		ft_sb(b);
	else if (ft_lstsize(*b) == 3)
		sort_threeb(b);
}
