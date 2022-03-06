/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 03:07:44 by brmohamm          #+#    #+#             */
/*   Updated: 2022/03/06 22:54:26 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*rb send the first one in 'b' to the last*/

void	rb(t_list **b, int f)
{
	t_variabl	var;
	
	if((*b) && (*b)->next)
	{
		var.temp = NULL;
		var.temp = ft_lstlast(*b);
		(*b)->prev = var.temp;
		var.temp->next = *b;
		*b = (*b)->next;
		(*b)->prev = NULL;
		var.temp->next->next = NULL;
		var.temp = NULL;
		if (f == 1)
			write(1, "rb\n", 3);
	}
	
}
/*rra send the last one in 'a' to the first*/

void	rra(t_list **a, int f)
{
	t_variabl	var;

	if((*a) && (*a)->next)
	{
		var.temp = NULL;
		var.temp = ft_lstlast_beforlast(*a);
		var.temp->next->prev = NULL;
		(*a)->prev = var.temp->next;
		var.temp->next->next = *a;
		*a = var.temp->next;
		var.temp->next = NULL;
		var.temp = NULL;
		if (f == 1)
			write(1, "rra\n", 4);
	}
	
}
/*rrb send the last one in 'b' to the first*/

void	rrb(t_list **b, int f)
{
	t_variabl	var;

	if((*b) && (*b)->next)
	{
		var.temp = NULL;
		var.temp = ft_lstlast_beforlast(*b);
		var.temp->next->prev = NULL;
		(*b)->prev = var.temp->next;
		var.temp->next->next = *b;
		*b = var.temp->next;
		var.temp->next = NULL;
		var.temp = NULL;
		if (f == 1)
			write(1, "rrb\n", 4);
	}

}
/*--ss-- sa and sb*/

void	ss(t_list **a, t_list **b, int f)
{
	sa(a, 0);
	if (*b != NULL)
		sb(b, 0);
	if (f == 1)
		write(1, "ss\n", 3);
}
/*---rr :  ra and rb----*/

void	rr(t_list **a, t_list **b, int f)
{
	ra(a, 0);
	if (*b != NULL)
		rb(b, 0);
	if (f == 1)
		write(1, "rr\n", 3);
}
