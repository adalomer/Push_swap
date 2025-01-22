#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void ft_sa(t_stack **a) {
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

void ft_sb(t_stack **b) {
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


void ft_ss(t_stack **a, t_stack **b) {
    t_stack *top_a;
    t_stack *next_a;
    t_stack *top_b;
    t_stack *next_b;

    if (a && *a && (*a)->next) {
        top_a = *a;
        next_a = (*a)->next;
        top_a->next = next_a->next;
        next_a->next = top_a;
        *a = next_a;
    }
    if (b && *b && (*b)->next) {
        top_b = *b;
        next_b = (*b)->next;
        top_b->next = next_b->next;
        next_b->next = top_b;
        *b = next_b;
    }
    write(1, "ss\n", 3);
}

void ft_pa(t_stack **a, t_stack **b) {
    t_stack *temp;

    if (!b || !(*b))
        return;
    temp = *b;
    *b = (*b)->next;
    temp->next = *a;
    *a = temp;
    write(1, "pa\n", 3);
}

void ft_pb(t_stack **a, t_stack **b) {
    t_stack *temp;

    if (!a || !(*a))
        return;
    temp = *a;
    *a = (*a)->next;
    temp->next = *b;
    *b = temp;
    write(1, "pb\n", 3);
}