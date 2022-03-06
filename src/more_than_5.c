/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 03:01:24 by brmohamm          #+#    #+#             */
/*   Updated: 2022/03/06 01:22:51 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	a_empti( t_list **a, t_list **b, t_variabl *var)
{
	t_list	*temp;

	while ((*a)->index > var->y)
	{
		temp = (*a);
		if (*a && (*a)->index > var->f - (var->nn + var->bb + var->cc)
				&& (*a)->index <= var->f - (var->bb + var->cc))
		{
			pb(a, b, 1);
			rb(b, 1);
			temp = (*a);
			var->gg++;
		}
		else
		{
			if(*a && temp->next)
			{
				ra(a, 1);
				temp = temp->next;
			}
		}
	}
	pb(a, b, 1);
	
}

t_list	*best_way(t_list **b, t_variabl *var, t_list **temp)
{
	t_list	*mediantemp;

	*temp = *b;
	while ((*temp)->index != var->z && (*temp)->next != NULL)
		(*temp) = (*temp)->next;
	mediantemp = *b;
	var->g = 0;
	while (mediantemp)
	{
		mediantemp = mediantemp->next;
		var->g++;
	}
	mediantemp = *b;
	var->y = 0;
	while (mediantemp)
	{
		if ((*temp)->index == mediantemp->index)
			break ;
		mediantemp = mediantemp->next;
		var->y++;
	}
	return (*temp);
}

void	send_from_b(t_list **a, t_list **b, t_variabl *var, t_list **temp)
{
	while (var->z > 0)
	{
		(*temp) = best_way(b, var, temp);
		if (var->y > var-> g / 2)
		{
			while ((*temp)->index != (*b)->index)
			{
				rrb(b, 1);
			}
		}
		else
		{
			while ((*temp)->index != (*b)->index)
			{
				rb(b, 1);
			}
		}
		if ((*temp)->index == (*b)->index)
		{
			pa(a, b, 1);
		}
		var->z--;
	}
}

void	more_than_5(t_list **a, t_list **b, t_variabl *var)
{
	t_list	*temp;
	t_list	*mediantemp;

	mediantemp = NULL;
	temp = NULL;
	var->g = 0;
	var->y = var->z;
	var->nn = var->z;
	var->bb = var->z;
	var->cc = var->z;
	while ((*a))
	{
		while (var->g < var->y)
		{
			if ((*a))
				a_empti(a, b, var);
			var->g++;
			if (var->gg == var->nn)
				var->bb = 0;
			if (var->gg == var->nn * 2)
				var->cc = 0;
		}
		var->y = var->y + var->z;
	}
	while(*a)
		pb(a, b, 1);
	var->z = var->f;
	send_from_b(a, b, var, &temp);
}
