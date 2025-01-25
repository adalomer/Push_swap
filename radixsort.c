#include "push_swap.h"

void sort_two(t_stack **a)
{
    if ((*a)->data > (*a)->next->data)
        ft_sa(a);
}

void sort_three(t_stack **a)
{
    if ((*a)->data > (*a)->next->data && (*a)->data > (*a)->next->next->data)
        ft_ra(a);
    if ((*a)->next->data > (*a)->data && (*a)->next->data > (*a)->next->next->data)
        ft_rra(a);
    if ((*a)->data > (*a)->next->data)
        ft_sa(a);
}

void move_min_to_top(t_stack **a, int size)
{
    int min_pos;

    min_pos = find_min_position(*a);
    while (min_pos != 0)
    {
        if (min_pos <= size / 2)
            ft_ra(a);
        else
            ft_rra(a);
        min_pos = find_min_position(*a);
    }
}

void sort_four(t_stack **a, t_stack **b)
{
    move_min_to_top(a, 4);
    ft_pb(a, b);
    sort_three(a);
    ft_pa(a, b);
}

void sort_five(t_stack **a, t_stack **b)
{
    move_min_to_top(a, 5);
    ft_pb(a, b);
    move_min_to_top(a, 4);
    ft_pb(a, b);
    sort_three(a);
    ft_pa(a, b);
    ft_pa(a, b);
}x

void smallsort(t_stack **a, t_stack **b, int size)
{
    if (size == 2)
        sort_two(a);
    else if (size == 3)
        sort_three(a);
    else if (size == 4)
        sort_four(a, b);
    else if (size == 5)
        sort_five(a, b);
}

int find_min_position(t_stack *a)
{
    int min_pos;
    int min_value;
    int i;

    min_pos = 0;
    min_value = a->data;
    i = 0;
    while (a)
    {
        if (a->data < min_value)
        {
            min_value = a->data;
            min_pos = i;
        }
        a = a->next;
        i++;
    }
    return min_pos;
}

void perform_radix_sort(t_stack **a, t_stack **b, int size, int max_bits)
{
    int i;
    int j;
    int num;

    i = 0;
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

void ft_radix_sort(t_stack **a, t_stack **b, int size)
{
    int max_bits;

    if (size <= 5)
    {
        smallsort(a, b, size);
        return;
    }

    max_bits = 0;
    while ((size - 1) >> max_bits)
        max_bits++;

    perform_radix_sort(a, b, size, max_bits);
}
