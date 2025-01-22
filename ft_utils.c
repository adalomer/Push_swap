#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // Sadece debug için, silinebilir

int ft_atoi(const char *str) {
    int neg;
    int i;
    int num;

    i = 0;
    neg = 1;
    num = 0;
    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
           || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        num = num * 10 + (str[i] - 48);
        i++;
    }
    return (num * neg);
}

int ft_lstsize(t_stack *lst) {
    int size;

    size = 0;
    while (lst) {
        size++;
        lst = lst->next;
    }
    return (size);
}

int ft_is_sorted(t_stack *a) {
    while (a && a->next) {
        if (a->data > a->next->data)
            return (0);
        a = a->next;
    }
    return (1);
}

void ft_error(t_stack **head) {
    t_stack *swap;
    
    if(head == NULL)
      return;
    swap = (*head);
    while ((*head) != NULL) {
        (*head) = (*head)->next;
        free(swap);
        swap = *(head);
    }
    write(2, "Error\n", 6); // Hata mesajı stderr'e yazılmalı
    exit(1);
}
void ft_checkrepeat(t_stack **head)
{
    t_stack *current;
    t_stack *check;

    if(head == NULL || (*head) == NULL)
        return;

    current = *head;
    check = (*head)->next;

    while(current)
    {
        while(check)
        {
            if(current->data == check->data)
            {
                ft_error(head);
                return; // ft_error fonksiyonu zaten çıkış yapıyor
            }
            check = check->next;
        }
        if(current->next == NULL )
            return;
        current = current->next;
        check = current->next;
    }
}

void ft_index(t_stack **head) {
    t_stack *current;
    t_stack *temp;
    int     index;
    int     size;

    size = ft_lstsize(*head);
    current = *head;
    while (current) {
        index = 0;
        temp = *head;
        while (temp) {
            if (current->data > temp->data)
                index++;
            temp = temp->next;
        }
        current->index = index;
        current = current->next;
    }
}
void ft_createnode(t_stack **a, int value) 
{
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    if (new_node == NULL) {
        printf("Bellek tahsisi başarısız.\n");
        return;
    }

    new_node->data = value;
    new_node->next = NULL;

    if (*a == NULL) 
    {  // İlk düğüm ekleniyorsa
        new_node->next = NULL;
        *a = new_node;
    } 
    else 
    {  // Listenin sonuna ekleme
        t_stack *current = *a;
        while (current->next != NULL)
            current = current->next;

        current->next = new_node;
    }
}

// Debug için (silinebilir)
void print_list(t_stack *head, char name) {
    printf("Stack %c: ", name);
    while (head) {
        printf("%d(%d) ", head->data, head->index);
        head = head->next;
    }
    printf("\n");
}