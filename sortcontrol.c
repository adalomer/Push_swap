/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortcontrol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 03:38:10 by omadali           #+#    #+#             */
/*   Updated: 2025/01/31 02:43:49 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	shrt(t_stack **a)
{
	return ((*a)->next->next->data);
}

void	sort_three(t_stack **a)
{
	if ((*a)->data > (*a)->next->data && (*a)->data > (*a)->next->next->data)
		ft_ra(a);
	if ((*a)->next->data > (*a)->data && (*a)->next->data > shrt(a))
		ft_rra(a);
	if ((*a)->data > (*a)->next->data)
		ft_sa(a);
}

void	sort_threeb(t_stack **b)
{
	if ((*b)->data < (*b)->next->data && (*b)->data < (*b)->next->next->data)
		ft_rb(b);
	if ((*b)->next->data < (*b)->data && (*b)->next->data < shrt(b))
		ft_rrb(b);
	if ((*b)->data < (*b)->next->data)
		ft_sb(b);
}

void	ft_checkrepeat(t_stack **head)
{
	t_stack	*current;
	t_stack	*check;

	if (head == NULL || (*head) == NULL)
		return ;
	current = *head;
	check = (*head)->next;
	while (current)
	{
		while (check)
		{
			if (current->data == check->data)
			{
				ft_error(head);
				return ;
			}
			check = check->next;
		}
		if (current->next == NULL )
			return ;
		current = current->next;
		check = current->next;
	}
}

int	ft_is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}
