/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <adalomer60@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:36:10 by omadali           #+#    #+#             */
/*   Updated: 2025/01/30 03:40:32 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int ft_createnode(t_stack **a, int value) 
{
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    if (new_node == NULL)
	{
        write(2,"error",6);
        return (0);
    }

    new_node->data = value;
    new_node->next = NULL;

    if (*a == NULL) 
    {
        new_node->next = NULL;
        *a = new_node;
    } 
    else 
    {
        t_stack *current = *a;
        while (current->next != NULL)
            current = current->next;

        current->next = new_node;
    }
	return(1);
}

void	ft_clear(t_stack **a, t_stack **b)
{
	while ((*a)) 
	{
        t_stack *temp = (*a);
        (*a) = (*a)->next;
        free(temp);
    }
	while ((*b)) {
        t_stack *temp = (*b);
        (*b) = (*b)->next;
        free(temp);
    }
}
void ft_free_split(char **split)
{
    int i;

    if (!split)
        return;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

int ft_is_numeric(char *str)
{
    int i;

    if (!str || !*str)
        return (0);
    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int ft_is_valid_int(char *str)
{
    long result;
    int sign;
    int i;

    if (!ft_is_numeric(str))
        return (0);
    result = 0;
    sign = 1;
    i = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i])
    {
        result = result * 10 + (str[i] - '0');
        if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
            return (0);
        i++;
    }
    return (1);
}

void ft_put_error(void)
{
    write(2, "Error\n", 6);
}

int ft_has_duplicates(t_stack *stack)
{
    t_stack *current;
    t_stack *runner;

    current = stack;
    while (current)
    {
        runner = current->next;
        while (runner)
        {
            if (current->data == runner->data)
                return (1);
            runner = runner->next;
        }
        current = current->next;
    }
    return (0);
}

int ft_validate_and_fill_stack(int argc, char **argv, t_stack **a)
{
    int i, j;
    char **split;

    i = 1;
    while (i < argc)
    {
        split = ft_split(argv[i], ' ');
        if (!split)
            return (ft_put_error(),ft_clear(a,NULL),1);
        j = 0;
        while (split[j])
        {
            if (!ft_is_valid_int(split[j]))
            {
                ft_put_error();
                ft_free_split(split);
				ft_clear(a,NULL);
                return (1);
            }
            ft_createnode(a, ft_atoi(split[j]));
            j++;
        }
        ft_free_split(split);
        i++;
    }
    if (ft_has_duplicates(*a))
    {
        ft_put_error();
        ft_clear(a, NULL);
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if (argc < 2)
        return (0);
    if (ft_validate_and_fill_stack(argc, argv, &a))
        return (1);
    if (!ft_is_sorted(a))
    {
        ft_index(&a);
        ft_sort(&a, &b, ft_lstsize(a));
    }
    ft_clear(&a, &b);
    return (0);
}

