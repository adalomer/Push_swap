#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void ft_sasb(t_stack **head,int i)
{
    t_stack *current = *head;
    t_stack *tmp;
    if(!head || !(*head)->next)
        return;
    tmp = current->next;
    current->next = current->next->next;
    tmp->next = current;
    *head = tmp;
    if(i==1)
        write(1,"sa\n",3);
    else if (i == 2);
        write(1,"sb\n",3);
}
void ft_pbpa(t_stack **heada, t_stack **headb,int i)
{
    t_stack *currenta = *heada;
    t_stack *currentb = *headb;
    if ( *heada == NULL )
        return;
    else if(*headb == NULL)
        ft_createnode(headb,(*heada)->data);
    else
    {
        t_stack *new_node = malloc(sizeof(t_stack));
        if (!new_node)
            return; // Bellek tahsisi başarısızsa çıkış yap
        new_node->data = (*heada)->data;
        new_node->next = *headb;
        *headb = new_node;
    }
    (*heada) = (*heada)->next;
    free(currenta);
    if(i == 1)
        write(1,"pb\n",3);
    else if (i == 2)
        write(1,"pa\n",3);
}
void ft_rarb(t_stack **head, int i)
{
    t_stack* current = *head;
    t_stack* firstHead = *head;

    if (current == NULL || current->next == NULL)
        return;
    (*head) = (*head)->next;
    while(current->next != NULL)
        current = current->next;
    current->next = firstHead; 
    firstHead->next = NULL;
    if(i == 1)
        write(1,"ra\n",3);
    else if(i == 2)
        write(1,"rb\n",3);
}

void    ft_rrarrb(t_stack **head, int i)
{
    t_stack* last= (*head);

    if(last == NULL || last->next == NULL)
        return;
    while(last->next->next != NULL)
        last = last->next;
    last->next->next = (*head);
    (*head) = last->next ;
    last->next = NULL;
    if(i == 1)
        write(1,"rra\n",4);
    else if (i == 2)
        write(1,"rrb",4);
}

void    ft_ss(t_stack** heada,t_stack** headb)
{
    ft_sasb(heada,3);
    ft_sasb(headb,3);
    write(1,"ss\n",3);
}