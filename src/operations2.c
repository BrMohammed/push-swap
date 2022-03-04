/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 03:07:44 by brmohamm          #+#    #+#             */
/*   Updated: 2022/03/04 03:10:00 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*rb send the first one in 'b' to the last*/

void	rb(t_list **b)
{
	t_variabl	var;

	var.temp = NULL;
	var.temp = ft_lstlast(*b);
	(*b)->prev = var.temp;
	var.temp->next = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	var.temp->next->next = NULL;
	var.temp = NULL;
	write(1, "rb\n", 3);
}
/*rra send the last one in 'a' to the first*/

void	rra(t_list **a)
{
	t_variabl	var;

	var.temp = NULL;
	var.temp = ft_lstlast_beforlast(*a);
	var.temp->next->prev = NULL;
	(*a)->prev = var.temp->next;
	var.temp->next->next = *a;
	*a = var.temp->next;
	var.temp->next = NULL;
	var.temp = NULL;
}
/*rrb send the last one in 'b' to the first*/

void	rrb(t_list **b)
{
	t_variabl	var;

	var.temp = NULL;
	var.temp = ft_lstlast_beforlast(*b);
	var.temp->next->prev = NULL;
	(*b)->prev = var.temp->next;
	var.temp->next->next = *b;
	*b = var.temp->next;
	var.temp->next = NULL;
	var.temp = NULL;
	write(1, "rrb\n", 4);
}
/*--ss-- sa and sb*/

void	ss(t_list **a, t_list **b)
{
	sa(a);
	if (*b != NULL)
		sb(b);
	write(1, "ss\n", 3);
}
/*---rr :  ra and rb----*/

void	rr(t_list **a, t_list **b)
{
	ra(a);
	if (*b != NULL)
		rb(b);
	write(1, "rr\n", 3);
}
