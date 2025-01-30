/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <adalomer60@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:35:09 by omadali           #+#    #+#             */
/*   Updated: 2025/01/30 03:36:32 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
    int	neg;
    int	i;
    int	num;

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

int ft_lstsize(t_stack *lst)
{
    int size;

    size = 0;
    while (lst) {
        size++;
        lst = lst->next;
    }
    return (size);
}

void ft_error(t_stack **head)
{
    t_stack *swap;
    
    if(head == NULL)
      return;
    swap = (*head);
    while ((*head) != NULL) {
        (*head) = (*head)->next;
        free(swap);
        swap = *(head);
    }
    write(2, "Error\n", 6);
    exit(1);
}

void ft_index(t_stack **head)
{
    t_stack *current;
    t_stack *temp;
    int     index;
	
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

