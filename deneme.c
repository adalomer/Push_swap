#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node* next;
} node;

int main(int argc , char **argv)
{
    int a = atoi(argv[4]);
    node* head = NULL;
    node* firstnode = (node *)malloc(sizeof(struct node));
    firstnode->data = atoi(argv[1]);
    node* secondnode = (node *)malloc(sizeof(struct node));
    firstnode->next = secondnode;
    secondnode->data = atoi(argv[2]);
    node* triplenode = (node *)malloc(sizeof(struct node));
    secondnode-> next = triplenode;
    triplenode-> data = atoi(argv[3]);
    head = firstnode;
    node* trip = head;
    while(trip != NULL)
    {
        printf("%d\n",trip->data);
        trip =trip->next;
    }
    printf("\n**********\n");
    trip = head;
    node* old = NULL;
    while(a > 0)
    {
        old = trip;
        trip= trip->next;
        a--;
    }
    old->next = trip->next;
    free(trip);
    trip = head;
    while(trip != NULL)
    {
        printf("%d\n",trip->data);
        trip = trip->next;   
    }

//   int a = atoi(argv[4]);
//     node* head = NULL;
//     node* firstnode = (node *)malloc(sizeof(struct node));
//     firstnode->data = atoi(argv[1]);
//     node* secondnode = (node *)malloc(sizeof(struct node));
//     firstnode->next = secondnode;
//     secondnode->data = atoi(argv[2]);
//     node* triplenode = (node *)malloc(sizeof(struct node));
//     secondnode-> next = triplenode;
//     triplenode-> data = atoi(argv[3]);
//     head = firstnode;
//     node* trip = head;
//     while(trip != NULL)
//     {
//         printf("%d\n",trip->data);
//         trip =trip->next;
//     }
//     printf("\n**********\n");
//     trip = head;
//     node* old = NULL;
//     while(a > 0)
//     {
//         old = trip;
//         trip= trip->next;
//         a--;
//     }
//     old->next = trip->next;
//     free(trip);
//     trip = head;
//     while(trip != NULL)
//     {
//         printf("%d\n",trip->data);
//         trip = trip->next;   
//     }
// 
//void ft_sa(t_a **a,t_b)
// {


// }
// void ft_createnode(s_a **a,int c)
// {
//     // if(*a == NULL)
//     // {
//     //     *a = (s_a *)malloc(sizeof(s_a));
//     //     if(a == NULL)
//     //         return;
//     //     (*a)-> next = NULL;
//     //     (*a)-> prev = NULL;
//     // }
//     s_a *current = *a;
//     s_a* new = (s_a *)malloc(sizeof(s_a));
//     if(new == NULL)
//         return;
//     new->data = c;
//     new->prev = *a;
//     new->next = NULL;
//     current->next = new;
//     current = new; 

// }
}