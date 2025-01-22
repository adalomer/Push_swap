#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// Error handling function
void ft_error(t_stack **head)
{
    t_stack *swap;

    while (*head)
    {
        swap = (*head)->next;
        free(*head);
        *head = swap;
    }
    write(1, "ERROR\n", 6);
    exit(1);
}

// Check for duplicates
void ft_checkrepeat(t_stack **head)
{
    t_stack *current = *head;
    t_stack *check;

    while (current)
    {
        check = current->next;
        while (check)
        {
            if (current->data == check->data)
                ft_error(head);
            check = check->next;
        }
        current = current->next;
    }
}

// Find the minimum value in the stack
int find_min(t_stack *stack)
{
    int min = stack->data;

    while (stack)
    {
        if (stack->data < min)
            min = stack->data;
        stack = stack->next;
    }
    return min;
}

// Find the maximum value in the stack
int find_max(t_stack *stack)
{
    int max = stack->data;

    while (stack)
    {
        if (stack->data > max)
            max = stack->data;
        stack = stack->next;
    }
    return max;
}

// Count the number of elements in the stack
int stack_size(t_stack *stack)
{
    int count = 0;

    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return count;
}

// Index the stack elements for sorting
void index_stack(t_stack **stack)
{
    t_stack *current;
    t_stack *compare;
    int index;

    current = *stack;
    while (current)
    {
        index = 0;
        compare = *stack;
        while (compare)
        {
            if (current->data > compare->data)
                index++;
            compare = compare->next;
        }
        current->index = index;
        current = current->next;
    }
}

// Radix sort implementation
void radix_sort(t_stack **a, t_stack **b)
{
    int max_bits;
    int i;
    int j;
    int size;
    t_stack *current;

    size = stack_size(*a);
    max_bits = 0;
    while ((size - 1) >> max_bits)
        max_bits++;

    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            current = *a;
            if (((current->index >> i) & 1) == 1)
                ft_rarb(a, 1); // Move to the bottom
            else
                ft_pbpa(a, b, 1); // Push to stack b
            j++;
        }
        while (*b)
            ft_pbpa(b, a, 2); // Push back to stack a
        i++;
    }
}

int main(int argc, char **argv)
{
    int i;
    t_stack *a = NULL;
    t_stack *b = NULL;

    if (argc < 2)
        return 0;

    i = 1;
    while (i < argc)
    {
        ft_createnode(&a, ft_atoi(argv[i]));
        i++;
    }

    ft_checkrepeat(&a);
    index_stack(&a);
    radix_sort(&a, &b);

    // Print sorted stack
    while (a)
    {
        printf("%d\n", a->data);
        a = a->next;
    }
    return 0;
}
