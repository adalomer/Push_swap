#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_stack {
    int data;
    int index;
    struct s_stack* next;
} t_stack;

// Yardımcı Fonksiyonlar
int     ft_atoi(const char *str);
int     ft_lstsize(t_stack *lst);
int     ft_is_sorted(t_stack *a);
void    ft_error(t_stack **head);
void    ft_index(t_stack **head);
void    ft_checkrepeat(t_stack **head);
void    ft_deletenode(t_stack **head, int value);
void    ft_createnode(t_stack **a, int value);

// Yığın İşlemleri
void    ft_sa(t_stack **a);
void    ft_sb(t_stack **b);
void    ft_ss(t_stack **a, t_stack **b);
void    ft_pa(t_stack **a, t_stack **b);
void    ft_pb(t_stack **a, t_stack **b);
void    ft_ra(t_stack **a);
void    ft_rb(t_stack **b);
void    ft_rr(t_stack **a, t_stack **b);
void    ft_rra(t_stack **a);
void    ft_rrb(t_stack **b);
void    ft_rrr(t_stack **a, t_stack **b);

// Sıralama Algoritması
void    ft_quick_sort(t_stack **a, t_stack **b, int len);
void    ft_recursive_sort(t_stack **a, t_stack **b, int len); // **DEĞİŞTİ:** ft_recursive_sort eklendi
void    ft_sort_three(t_stack **a); // **YENİ:** 3 eleman için sıralama

// Debug için (silinebilir)
void    print_list(t_stack *head, char name);



#endif