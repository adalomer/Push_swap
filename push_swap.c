#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"


void    ft_deletenode(s_a **head, int value)
{
    s_a *current = *head;
    s_a *prev = NULL;

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

void ft_createnode(s_a **a, int value) 
{
    s_a *new_node = (s_a *)malloc(sizeof(s_a));
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
        s_a *current = *a;
        while (current->next != NULL)
            current = current->next;

        current->next = new_node;
    }
}

int main(int argc , char **argv)
{
    int b = argc - 1;
    int d = 1;
    s_a* a =NULL;
    while(b--> 0)
        ft_createnode(&a,ft_atoi(argv[d++]));
    
    
    return(0);
}