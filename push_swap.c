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
    //ft_quick_sort(&a, &b, ft_lstsize(a));
	ft_radix_sort(&a,&b,ft_lstsize(a));
    //Debug için (silinebilir)
    print_list(a, 'a');
    //print_list(b, 'b');

    // a listesini temizle
    while (a) {
        t_stack *temp = a;
        a = a->next;
        free(temp);
    }
    return (0);
}