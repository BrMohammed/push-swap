/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 00:49:41 by brmohamm          #+#    #+#             */
/*   Updated: 2022/03/07 01:05:09 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_and_creat_a(char **argv, t_variabl *var, t_list **a)
{
	t_list	*temp;

	temp = NULL;
	while (argv[var->f])
	{
		if (ft_isdigit(argv[var->f]) == 1)
		{
			write(1, "Error\n", 6);
			exit(2);
		}
		temp = ft_lstnew(ft_atoi(argv[var->f]));
		ft_lstadd_back(a, temp);
		var->f++;
	}
	if (check_double(*a) == -1)
	{
		write(1, "Error\n", 6);
		exit(2);
	}
}

void	error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	compile(char *r, t_list **a, t_list **b)
{
	if (ft_strcmp("sa\n", r) == 0)
		sa(a, 0);
	else if (ft_strcmp("sb\n", r) == 0)
		sb(b, 0);
	else if (ft_strcmp("ss\n", r) == 0)
		ss(a, b, 0);
	else if (ft_strcmp("pa\n", r) == 0)
		pa(a, b, 0);
	else if (ft_strcmp("pb\n", r) == 0)
		pb(a, b, 0);
	else if (ft_strcmp("ra\n", r) == 0)
		ra(a, 0);
	else if (ft_strcmp("rb\n", r) == 0)
		rb(b, 0);
	else if (ft_strcmp("rr\n", r) == 0)
		rr(a, b, 0);
	else if (ft_strcmp("rra\n", r) == 0)
		rra(a, 0);
	else if (ft_strcmp("rrb\n", r) == 0)
		rrb(b, 0);
	else if (ft_strcmp("rrr\n", r) == 0)
		rrr(a, b, 0);
	else if (r != NULL)
		error();
}

void	cheker_mac(t_list **a, t_list **b)
{
	char	*r;

	r = get_next_line(0);
	while (r != NULL)
	{	
		compile(r, a, b);
		free(r);
		r = get_next_line(0);
	}
	if (*a && check_order(*a) == -1 && *b == NULL)
	{
		write(1, "OK\n", 3);
		exit(0);
	}
	else
	{
		write(1, "KO\n", 3);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	t_variabl	var;

	var.f = 1;
	b = NULL;
	if (argc > 2)
	{
		check_and_creat_a(argv, &var, &a);
		cheker_mac(&a, &b);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
