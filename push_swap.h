#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct t_a {
    int data;
    struct t_a* next;
} s_a;
typedef struct t_b {
    int data;
    struct t_b* next;
} s_b;


int		ft_atoi(const char *str);
void ft_createnode(s_a **a, int value);
void ft_sa(s_a **head);

#endif