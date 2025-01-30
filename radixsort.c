/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:29:51 by omadali           #+#    #+#             */
/*   Updated: 2025/01/31 02:43:26 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	perform_radix_sort(t_stack **a, t_stack **b, int size)
{
	int	max_bits;
	int	i;
	int	j;
	int	num;

	max_bits = 0;
	i = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = (*a)->index;
			if ((num >> i) & 1)
				ft_ra(a);
			else
				ft_pb(a, b);
			j++;
		}
		while (*b)
			ft_pa(a, b);
		i++;
	}
}

void	ft_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
	{
		if ((*a)->data > (*a)->next->data)
			ft_sa(a);
		return ;
	}
	else if (size == 3)
	{
		sort_three(a);
		return ;
	}
	if (size <= 6)
	{
		ft_recursive_sort(a, b, size);
		return ;
	}
	perform_radix_sort(a, b, size);
}
