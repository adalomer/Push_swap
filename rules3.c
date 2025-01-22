#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void ft_rrr(t_stack **a, t_stack **b) {
    t_stack *last_a;
    t_stack *before_last_a;
    t_stack *last_b;
    t_stack *before_last_b;

    if (a && *a && (*a)->next) {
        last_a = *a;
        before_last_a = NULL;
        while (last_a->next) {
            before_last_a = last_a;
            last_a = last_a->next;
        }
        before_last_a->next = NULL;
        last_a->next = *a;
        *a = last_a;
    }
    if (b && *b && (*b)->next) {
        last_b = *b;
        before_last_b = NULL;
        while (last_b->next) {
            before_last_b = last_b;
            last_b = last_b->next;
        }
        before_last_b->next = NULL;
        last_b->next = *b;
        *b = last_b;
    }
    write(1, "rrr\n", 4);
}