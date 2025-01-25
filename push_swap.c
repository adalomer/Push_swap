#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
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