/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:36:10 by omadali           #+#    #+#             */
/*   Updated: 2025/01/31 02:55:15 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_createnode(t_stack **a, int value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		write(2, "Error\n", 6);
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
		current = *a;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	return (1);
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	ft_process_split(char **split, t_stack **a)
{
	int	j;

	j = 0;
	while (split[j])
	{
		if (!ft_is_valid_int(split[j]))
		{
			ft_free_split(split);
			ft_error(a);
			return (1);
		}
		ft_createnode(a, ft_atoi((split[j])));
		j++;
	}
	ft_free_split(split);
	return (0);
}

int	ft_validate_and_fill_stack(int argc, char **argv, t_stack **a)
{
	int		i;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (ft_error(a), 1);
		if (ft_process_split(split, a))
			return (1);
		i++;
	}
	if ((ft_has_duplicates((*a))))
	{
		ft_error(a);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

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
