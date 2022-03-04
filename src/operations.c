# include "../push_swap.h"

void sa(t_list **a) //sa revest the ferst and the seconde in 'a'
{
    t_variabl var;

    var.temp = NULL;
	var.temp = *a;
	*a = (*a)->next; 
	var.temp->next = (*a)->next;
	var.temp->prev = (*a);
	(*a)->next = var.temp;
	(*a)->prev = NULL;
	var.temp = NULL;
	write(1,"sa\n",3);
}

void sb(t_list **b) //sb revest the ferst and the seconde in 'b'
{
    t_variabl var;

    var.temp = NULL;
	var.temp = *b;
	*b = (*b)->next;
	var.temp->next = (*b)->next;
	var.temp->prev = (*b);
	(*b)->next = var.temp;
	(*b)->prev = NULL;
	var.temp = NULL;
	write(1,"sb\n",3);
}

void pb(t_list **a, t_list **b) //pb send the first one in 'a' to the first in 'b'
{
    t_variabl var;

    var.temp = NULL;
	var.temp = *a;
	
	if(*b)
		(*b)->prev = *a;
	(*a) = (*a)->next;
	if(*a)
		(*a)->prev = NULL;
	var.temp->next = *b;
	*b = var.temp;
	var.temp = NULL;
	write(1,"pb\n",3);
}

void pa(t_list **a, t_list **b) //pa send the first one in 'b' to the first in 'a'
{
    t_variabl var;

    var.temp = NULL;
	var.temp = *b;
	*b = (*b)->next;
	var.temp->next = *a;
	*a = var.temp;
	var.temp = NULL;
	write(1,"pa\n",3);
}

void ra(t_list **a) //ra send the first one in 'a' to the last
{
    t_variabl var;

    var.temp = NULL;
	var.temp = ft_lstlast(*a);
	(*a)->prev = var.temp;
	var.temp->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	var.temp->next->next = NULL;
	var.temp = NULL;
	write(1,"ra\n",3);
}
