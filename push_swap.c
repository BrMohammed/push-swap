/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 03:27:03 by brmohamm          #+#    #+#             */
/*   Updated: 2022/03/04 03:27:03 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	printf("list: ============================\n");
	while (tmp)
	{
		printf("%d => %d\n", tmp->content, tmp->index);
		tmp = tmp->next;
	}
	printf("=================================\n");
}

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
	if (check_order(*a) == -1)
		exit (2);
}

void	lenth_of_a(t_list *a, t_variabl *var)
{
	t_list	*temp;

	temp = a;
	var->f = 0;
	while (temp)
	{
		temp = temp->next;
		var->f++;
	}
}

void	rang(t_list **a, t_list **b, t_variabl *var)
{
	var->z = 0;
	if (var->f <= 5)
		less_than_5(a, b, var->f);
	else if (var->f > 5 && var->f <= 70)
		var->z = var->f / 2;
	else if (var->f <= 100)
		var->z = var->f / 7;
	else
		var->z = var->f / 14;
}

int	main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	t_list		*temp;
	t_variabl	var;

	var.f = 1;
	b = NULL;
	temp = NULL;
	var.z = 0;
	if (argc > 2)
	{
		check_and_creat_a(argv, &var, &a);
		lenth_of_a(a, &var);
		insert_the_index(a, var.f);
		rang(&a, &b, &var);
		more_than_5(&a, &b, &var);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
