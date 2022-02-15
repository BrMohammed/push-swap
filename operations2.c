# include "push_swap.h"

void rb(t_list **b) //rb send the first one in 'b' to the last
{
    t_variabl var;

    var.temp = NULL;
	var.temp =ft_lstlast(*b);
	var.temp->next = *b;
	*b = (*b)->next;
	var.temp->next->next = NULL;
	var.temp = NULL; 
}

void rra(t_list **a) //rra send the last one in 'a' to the first
{
    t_variabl var;

    var.temp = NULL;
	var.temp = ft_lstlast_beforlast(*a);
	var.temp->next->next = *a;
	*a = var.temp->next;
	var.temp->next = NULL;
	var.temp = NULL;
}

void rrb(t_list **b) //rrb send the last one in 'b' to the first
{
    t_variabl var;

    var.temp = NULL;
	var.temp = ft_lstlast_beforlast(*b);
	var.temp->next->next = *b;
	*b = var.temp->next;
	var.temp->next = NULL;
	var.temp = NULL;
}