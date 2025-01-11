#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int		ft_atoi(const char *str)
{
	int neg;
	int i;
	int num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

void	ft_error(t_stack **head)
{
	t_stack* swap = (*head);
	while((*head) != NULL)
	{
		(*head) = (*head)->next;
		free(swap);
		swap = *(head);
	}
	write(1,"ERROR\n",6);
	return;
}
void ft_checkrepeat(t_stack **head)
{
	t_stack *current = *head;
	t_stack *check = (*head)->next;

	while(current)
	{
		while(check)
		{
			if(current->data == check->data)
			{
				ft_error(head);
				return;
			}
			check = check->next;
		}
		if(current->next == NULL )
			return;
		current = current->next;
		check = current->next;
	}
}


