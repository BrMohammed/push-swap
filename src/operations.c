/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 03:04:23 by brmohamm          #+#    #+#             */
/*   Updated: 2022/03/06 05:54:50 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*sa revest the ferst and the seconde in 'a'*/
void	sa(t_list **a, int f)
{
	t_variabl	var;
	
	if((*a)->next)
	{
		var.temp = NULL;
		var.temp = *a;
		*a = (*a)->next;
		var.temp->next = (*a)->next;
		var.temp->prev = (*a);
		(*a)->next = var.temp;
		(*a)->prev = NULL;
		var.temp = NULL;
		if (f == 1)
			write(1, "sa\n", 3);
	}
	
}
/*sb revest the ferst and the seconde in 'b'*/

void	sb(t_list **b, int f)
{
	t_variabl	var;

	if((*b)->next)
	{
		var.temp = NULL;
		var.temp = *b;
		*b = (*b)->next;
		var.temp->next = (*b)->next;
		var.temp->prev = (*b);
		(*b)->next = var.temp;
		(*b)->prev = NULL;
		var.temp = NULL;
		if (f == 1)
			write(1, "sb\n", 3);
	}
	
}
/*pb send the first one in 'a' to the first in 'b'*/

void	pb(t_list **a, t_list **b, int f)
{
	t_variabl	var;

	if(*a)
	{
		var.temp = NULL;
		var.temp = *a;
		if (*b)
			(*b)->prev = *a;
		(*a) = (*a)->next;
		if (*a)
			(*a)->prev = NULL;
		var.temp->next = *b;
		*b = var.temp;
		var.temp = NULL;
		if (f == 1)
			write(1, "pb\n", 3);
	}
	
}
/*pa send the first one in 'b' to the first in 'a'*/

void	pa(t_list **a, t_list **b, int f)
{
	t_variabl	var;

	if((*b))
	{
		var.temp = NULL;
		var.temp = *b;
		*b = (*b)->next;
		var.temp->next = *a;
		*a = var.temp;
		var.temp = NULL;
		if (f == 1)
			write(1, "pa\n", 3);
	}

}
/*ra send the first one in 'a' to the last*/

void	ra(t_list **a, int f)
{
	t_variabl	var;

	if((*a)->next)
	{
		var.temp = NULL;
		var.temp = ft_lstlast(*a);
		(*a)->prev = var.temp;
		var.temp->next = *a;
		*a = (*a)->next;
		(*a)->prev = NULL;
		var.temp->next->next = NULL;
		var.temp = NULL;
		if (f == 1)
			write(1, "ra\n", 3);
	}
	
}
