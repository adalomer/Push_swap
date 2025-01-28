/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <adalomer60@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:57:27 by omadali           #+#    #+#             */
/*   Updated: 2025/01/28 15:59:43 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

size_t	ft_strlen(const char *c)
{
	size_t	a;

	a = 0;
	while (c[a] != '\0')
		a++;
	return (a);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*c;
	int		d;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	c = (char *)malloc(sizeof(char) * (a + b + 1));
	if (!c)
		return (NULL);
	d = 0;
	while (d < a)
	{
		c[d] = s1[d];
		d++;
	}
	while (d < a + b)
	{
		c[d] = s2[d - a];
		d++;
	}
	c[d] = '\0';
	return (c);
}