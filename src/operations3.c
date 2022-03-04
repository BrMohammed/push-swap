/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 03:10:06 by brmohamm          #+#    #+#             */
/*   Updated: 2022/03/04 03:11:26 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*-rrr : rra and rrb at the same time.*/

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	if (*b != NULL)
		rrb(b);
	write(1, "rrr\n", 4);
}

int	check_double(t_list *a)
{
	t_list	*temp;

	temp = a;
	while (a)
	{
		if (a->next != NULL)
			temp = temp->next;
		if (a->content == temp->content && a->next != NULL)
			return (-1);
		if (temp->next == NULL)
		{
			a = a->next;
			temp = a;
		}
	}
	return (0);
}

int	ft_isdigit01(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_isdigit(char *c)
{
	int	n;

	n = 0;
	if (c[0] == '\0')
		return (1);
	while (c[n])
	{
		if (ft_isdigit01(c[n]) == 0)
			return (1);
		n++;
	}
	return (0);
}
