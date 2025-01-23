#include "push_swap.h"

int is_sorted_order(t_stack **s, int a, int b, int c)
{
    int da;
    int db;
    int dc;

    da = (*s)->index;
    db = (*s)->next->index;
    dc = (*s)->next->next->index;
    return (!((da > db) ^ (a > b)) && !((dc > db) ^ (c > b))
            && !((da > dc) ^ (a > c)));
}

void ft_sort_top_three_asc(t_stack **a)
{
    if (is_sorted_order(a, 1, 2, 3))
        return;
    if (is_sorted_order(a, 3, 1, 2) || is_sorted_order(a, 3, 2, 1))
        ft_sa(a);
    if (is_sorted_order(a, 1, 3, 2) || is_sorted_order(a, 2, 3, 1))
    {
        ft_ra(a);
        ft_sa(a);
        ft_rra(a);
    }
    if (is_sorted_order(a, 2, 1, 3))
        ft_sa(a);
}

void ft_sort_three_asc(t_stack **a)
{
    if (is_sorted_order(a, 1, 2, 3))
        return;
    if (is_sorted_order(a, 3, 1, 2) || is_sorted_order(a, 3, 2, 1))
        ft_ra(a);
    if (is_sorted_order(a, 1, 3, 2) || is_sorted_order(a, 2, 3, 1))
        ft_rra(a);
    if (is_sorted_order(a, 2, 1, 3))
        ft_sa(a);
}

void ft_sort_top_three_desc(t_stack **b)
{
    if (is_sorted_order(b, 3, 2, 1))
        return;
    if (is_sorted_order(b, 1, 2, 3) || is_sorted_order(b, 1, 3, 2))
        ft_sb(b);
    if (is_sorted_order(b, 3, 1, 2) || is_sorted_order(b, 2, 1, 3))
    {
        ft_rb(b);
        ft_sb(b);
        ft_rrb(b);
    }
    if (is_sorted_order(b, 2, 3, 1))
        ft_sb(b);
}
