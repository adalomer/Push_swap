#include "push_swap.h"
#include <stdio.h> // Sadece debug için, silinebilir
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
    int ra_count = 0;
    t_stack *temp;
    int i = 0;
    int pivot;

    if (len <= 3) 
    {
        if (len == 2 && (*a)->index > (*a)->next->index)
            ft_sa(a);
        else if (len == 3)
            ft_sort_three(a);
        return;
    }
    pivot = pivotfinder(a,len);
    int push_c = len / 2 ;
    while (i < len && push_c)
    {
        if ((*a)->index < pivot && push_c--)
        {
            ft_pb(a, b);
            pb_count++;
        }
        else 
        {
            ft_ra(a);
            ra_count++;
        }
        i++;
    }
    while (ra_count--) 
        ft_rra(a);
    ft_recursive_sort(a, b, len - pb_count); // Pivot üstü (stack_a'da kalanlar)
    int push_a = pb_count;
    while (pb_count--) {
        ft_pa(a, b);
    }
    ft_recursive_sort(a, b, push_a  + (len / 2 ) % 2);      // Pivot altı (stack_b'ye gidenler)
}

void ft_quick_sort(t_stack **a, t_stack **b, int len)
{
    if (ft_is_sorted(*a))
        return;
    if (len <= 3) 
    {
        if (len == 2) 
        {
            if ((*a)->index > (*a)->next->index)
                ft_sa(a);
        } else if (len == 3)
        {
            if ((*a)->index > (*a)->next->index && (*a)->index > (*a)->next->next->index)
            {
                ft_ra(a);
                if ((*a)->index > (*a)->next->index)
                    ft_sa(a);
            } else if ((*a)->index > (*a)->next->index)
                ft_sa(a);
                else if ((*a)->next->index > (*a)->next->next->index) 
                {
                    ft_rra(a);
                    if ((*a)->index > (*a)->next->index)
                        ft_sa(a);
                }
        }
        return;
    }
    ft_recursive_sort(a,b,len);
}
void ft_sort_three(t_stack **a) {
    if ((*a)->index > (*a)->next->index && (*a)->index > (*a)->next->next->index) {
        ft_ra(a);
        if ((*a)->index > (*a)->next->index)
            ft_sa(a);
    } else if ((*a)->index > (*a)->next->index) {
        ft_sa(a);
    } else if ((*a)->next->index > (*a)->next->next->index) {
        ft_rra(a);
        if ((*a)->index > (*a)->next->index)
            ft_sa(a);
    }
}