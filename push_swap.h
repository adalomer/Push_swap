#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_stack {
    int data;
    struct s_stack* next;
} t_stack;

int		ft_atoi(const char *str);


void ft_createnode(t_stack **a, int value);
void ft_checkrepeat(t_stack **head);


void ft_sasb(t_stack **headi, int i);
void ft_pbpa(t_stack **heada, t_stack **headb, int i);
void ft_rarb(t_stack **head, int i);
void    ft_rrarrb(t_stack **head, int i);
void    ft_rrr(t_stack** heada, t_stack** headb);
void    ft_rr(t_stack** heada,t_stack** headb);

#endif