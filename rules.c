#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void ft_sa(s_a **head)
{
    s_a *current = *head;
    s_a *tmp;
    if(!head || !(*head)->next)
        return;

    tmp = current->next;
    current->next = current->next->next;
    tmp->next = current;
    *head = tmp;
    write(1,"sa\n",3);
}
void ft_sb(s_b **head)
{

}