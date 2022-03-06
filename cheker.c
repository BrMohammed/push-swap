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

void compile(char *r,int er,t_list **a, t_list **b)
{
    if(ft_strcmp("sa", r) == -10)
        sa(a,0);
   	else if (ft_strcmp("sb", r) == -10)
        sb(b,0);
	else if(ft_strcmp("ss", r) == -10)
        ss(a, b, 0);
   	else if (ft_strcmp("pa", r) == -10)
        pa(a, b, 0);
	else if (ft_strcmp("pb", r) == -10)
        pb(a, b, 0);
	else if (ft_strcmp("ra", r) == -10)
        ra(a, 0);
	else if (ft_strcmp("rb", r) == -10)
        rb(b, 0);
	else if (ft_strcmp("rr", r) == -10)
        rr(a, b, 0);
	else if (ft_strcmp("rra", r) == -10)
       rra(a, 0);
	else if (ft_strcmp("rrb", r) == -10)
		rrb(b, 0);
	else if (ft_strcmp("rrr", r) == -10)
        rrr(a, b, 0);
	else if(er != 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
		
}



void	cheker_mac(t_list **a, t_list **b)
{
	char	r[10240];
	int		error;
	
   
    error = 1;
	r[0] = '\0';
	while (error != 0)
	{
		error = read(0, r, 10240);
		r[error] = '\0';
       	compile(r,error,a,b);
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
void	print_stack(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	printf("list: ============================\n");
	while (tmp)
	{
		printf("%d \n", tmp->content);
		tmp = tmp->next;
	}
	printf("=================================\n");
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
        cheker_mac(&a, &b);
		
	}
	else
		write(1, "Error\n", 6);
	return (0);
}