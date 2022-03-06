/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:31:00 by brmohamm          #+#    #+#             */
/*   Updated: 2022/03/06 22:03:38 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	if_more_than_3(int z, t_list **a, t_list **b)
{
	z = 2;
	int vv = 0;
	while (z < 3 && vv < 2)
	{
		while ((*a)->index > z)
			ra(a, 1);
		pb(a, b, 1);
		vv++;
	}
	if((*b)->index < (*b)->next->index)
	{
		sb(b,1);
	}
}

void	middle(t_list *mediantemp, t_list *tempa, t_list *temp, t_list **a)
{
	while (mediantemp->index < mediantemp->next->index)
	{
		mediantemp = mediantemp->next;
		if (mediantemp->next == NULL)
			break ;
	}
	if ((*a)->index > (*a)->next->index)
		sa(a, 1);
	tempa = ft_lstlast((*a));
	if (mediantemp->index > tempa->index)
	{
		rra(a, 1);
		temp = (*a);
	}
	tempa = ft_lstlast((*a));
	if ((*a)->index > tempa->index && (*a)->index > mediantemp->index)
	{
		ra(a, 1);
		temp = (*a);
	}
}

void	from_b_to_a(t_list **a, t_list **b)
{
	while (*b)
		pa(a, b, 1);
}

void	less_than_5(t_list **a, t_list **b, int f)
{
	int		z;
	t_list	*temp;
	t_list	*tempa;
	t_list	*mediantemp;

	z = 0;
	if (f > 3)
		if_more_than_3(z, a, b);
	temp = *a;
	while (temp)
	{
		tempa = ft_lstlast(*a);
		temp = *a;
		while (temp)
		{
			temp = ft_lstlast(*a);
			mediantemp = *a;
			middle(mediantemp, tempa, temp, a);
			temp = temp->next;
		}
	}
	from_b_to_a(a, b);
	exit(0);
}
