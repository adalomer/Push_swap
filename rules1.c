#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void ft_ra(t_stack **a) {
    t_stack *first;
    t_stack *last;

    if (!a || !(*a) || !(*a)->next)
        return;
    first = *a;
    last = *a;
    *a = (*a)->next;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
    write(1, "ra\n", 3);
}

void ft_rb(t_stack **b) {
    t_stack *first;
    t_stack *last;

    if (!b || !(*b) || !(*b)->next)
        return;
    first = *b;
    last = *b;
    *b = (*b)->next;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
    write(1, "rb\n", 3);
}

void ft_rra(t_stack **a) {
    t_stack *last;
    t_stack *before_last;

    if (!a || !(*a) || !(*a)->next)
        return;
    last = *a;
    before_last = NULL;
    while (last->next) {
        before_last = last;
        last = last->next;
    }
    before_last->next = NULL;
    last->next = *a;
    *a = last;
    write(1, "rra\n", 4);
}

void ft_rrb(t_stack **b) {
    t_stack *last;
    t_stack *before_last;

    if (!b || !(*b) || !(*b)->next)
        return;
    last = *b;
    before_last = NULL;
    while (last->next) {
        before_last = last;
        last = last->next;
    }
    before_last->next = NULL;
    last->next = *b;
    *b = last;
    write(1, "rrb\n", 4);
}