#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_atoi(const char *str)
{
    int neg = 1;
    int num = 0;
    while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' || *str == '\f' || *str == '\r')
        str++;
    if (*str == '-' || *str == '+')
        neg = (*str++ == '-') ? -1 : 1;
    while (*str >= '0' && *str <= '9')
        num = num * 10 + (*str++ - '0');
    return (num * neg);
}

void ft_error(t_stack **head)
{
    t_stack *temp;
    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    write(1, "ERROR\n", 6);
    exit(1);
}

void ft_checkrepeat(t_stack **head)
{
    t_stack *current = *head;
    while (current)
    {
        t_stack *check = current->next;
        while (check)
        {
            if (current->data == check->data)
                ft_error(head);
            check = check->next;
        }
        current = current->next;
    }
}

void ft_createnode(t_stack **a, int value)
{
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        ft_error(a);
    new_node->data = value;
    new_node->next = NULL;
    if (*a == NULL)
        *a = new_node;
    else
    {
        t_stack *current = *a;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
}

void ft_sasb(t_stack **head, int i)
{
    if (!head || !(*head) || !(*head)->next)
        return;
    t_stack *tmp = (*head)->next;
    (*head)->next = tmp->next;
    tmp->next = *head;
    *head = tmp;
    if (i == 1)
        write(1, "sa\n", 3);
    else if (i == 2)
        write(1, "sb\n", 3);
}

void ft_pbpa(t_stack **src, t_stack **dest, int i)
{
    if (!src || !(*src))
        return;
    t_stack *temp = *src;
    *src = (*src)->next;
    temp->next = *dest;
    *dest = temp;
    if (i == 1)
        write(1, "pb\n", 3);
    else if (i == 2)
        write(1, "pa\n", 3);
}

void ft_rarb(t_stack **head, int i)
{
    if (!head || !(*head) || !(*head)->next)
        return;
    t_stack *current = *head;
    *head = (*head)->next;
    t_stack *last = current;
    while (last->next)
        last = last->next;
    last->next = current;
    current->next = NULL;
    if (i == 1)
        write(1, "ra\n", 3);
    else if (i == 2)
        write(1, "rb\n", 3);
}

void ft_rrarrb(t_stack **head, int i)
{
    if (!head || !(*head) || !(*head)->next)
        return;
    t_stack *prev = NULL;
    t_stack *current = *head;
    while (current->next)
    {
        prev = current;
        current = current->next;
    }
    current->next = *head;
    *head = current;
    prev->next = NULL;
    if (i == 1)
        write(1, "rra\n", 4);
    else if (i == 2)
        write(1, "rrb\n", 4);
}

void sort_three(t_stack **stack)
{
    int a = (*stack)->data;
    int b = (*stack)->next->data;
    int c = (*stack)->next->next->data;

    if (a > b && b < c && a < c)
        ft_sasb(stack, 1);
    else if (a > b && b > c)
    {
        ft_sasb(stack, 1);
        ft_rrarrb(stack, 1);
    }
    else if (a > b && b < c && a > c)
        ft_rarb(stack, 1);
    else if (a < b && b > c && a < c)
    {
        ft_sasb(stack, 1);
        ft_rarb(stack, 1);
    }
    else if (a < b && b > c && a > c)
        ft_rrarrb(stack, 1);
}

void ft_sort(t_stack **a, t_stack **b, int size)
{
    if (size == 2 && (*a)->data > (*a)->next->data)
        ft_sasb(a, 1);
    else if (size == 3)
        sort_three(a);
    else
    {
        // Simplified sorting logic for larger sizes.
        while (*a)
            ft_pbpa(a, b, 1);
        while (*b)
            ft_pbpa(b, a, 2);
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (0);

    t_stack *a = NULL;
    t_stack *b = NULL;

    for (int i = 1; i < argc; i++)
        ft_createnode(&a, ft_atoi(argv[i]));

    ft_checkrepeat(&a);
    ft_sort(&a, &b, argc - 1);

    while (a)
    {
        printf("%d\n", a->data);
        a = a->next;
    }

    return (0);
}
