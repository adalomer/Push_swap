#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"


void    ft_deletenode(t_stack **head, int value)
{
    t_stack *current = *head;
    t_stack *prev = NULL;

    while(current != NULL)
    {
        if(current->data == value)
        {
            if(prev == NULL)
            {
                *head = current->next;
                free(current);
                current = *head;
            }
            else
            {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        }
        else
        {
            prev = current;
            current = current->next;
        }
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

int main(int argc , char **argv)
{
    int b = argc - 1;
    int d = 1;
    t_stack* a =NULL;
    t_stack* g = NULL;
    while(b--> 0)
        ft_createnode(&a,ft_atoi(argv[d++]));
    ft_pbpa(&g,&a,2);
    ft_pbpa(&g,&a,2);
    ft_pbpa(&g,&a,2);
    ft_rrarrb(&a,1);
    ft_rrr(&a,&g);
    ft_pbpa(&a,&g,1);
    ft_pbpa(&a,&g,1);
    ft_sasb(&g,2);
    ft_pbpa(&g,&a,2);
    ft_sasb(&g,2);
    ft_pbpa(&g,&a,2);
    ft_pbpa(&g,&a,2);
    b = argc-1;
    while (a)
    {
        printf("%d\n",a->data);
        a = a->next;
    }
    while(g)
    {
        printf("*********");
        printf("%d\n",g->data);
        g =g->next;
    }
    
    return(0);
}