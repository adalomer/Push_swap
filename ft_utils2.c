/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <adalomer60@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:36:41 by omadali           #+#    #+#             */
/*   Updated: 2025/02/03 18:26:11 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	ft_is_numeric(char *str)
{
	int	i;

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

int	ft_is_valid_int(char *str)
{
	int		sign;
	int		i;
	long	result;

	if (!(ft_is_numeric(str)))
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
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

void	ft_put_error(void)
{
	write(2, "Error\n", 6);
}

int	ft_has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

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

int	ft_control(char *a)
{
	int	b;

	b = 0;
	if (!a)
		return (1);
	while (a[b])
	{
		if (a[b] != 32)
			return (0);
		b++;
	}
	return (1);
}
