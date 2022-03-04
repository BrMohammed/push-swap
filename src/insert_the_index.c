/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_the_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 03:12:23 by brmohamm          #+#    #+#             */
/*   Updated: 2022/03/04 03:26:46 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lbedya(t_list **tempa, t_list *a, t_list **indextemp)
{
	(*tempa) = a;
	while ((*tempa))
	{
		if ((*tempa)->index == -1)
		{
			*indextemp = (*tempa);
			break ;
		}
		(*tempa) = (*tempa)->next;
	}
}

void	insert_the_index(t_list *a, int i)
{
	t_list	*indextemp;
	t_list	*tempa;
	int		g;
	int		t;

	g = i;
	t = 0;
	while (g > 0)
	{
		lbedya(&tempa, a, &indextemp);
		tempa = a;
		while (t < i)
		{
			if (tempa->content > indextemp->content && tempa->index == -1)
				indextemp = tempa;
			if (tempa)
				tempa = tempa->next;
			t++;
		}
		if (indextemp->content != -1)
			indextemp->index = g;
		t = 0;
		g--;
	}
}
