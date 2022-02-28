# include "../push_swap.h"

void rb(t_list **b) //rb send the first one in 'b' to the last
{
    t_variabl var;

    var.temp = NULL;
	var.temp =ft_lstlast(*b);
	(*b)->prev = var.temp;
	var.temp->next = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	var.temp->next->next = NULL;
	var.temp = NULL; 
}

void rra(t_list **a) //rra send the last one in 'a' to the first
{
    t_variabl var;

    var.temp = NULL;
	var.temp = ft_lstlast_beforlast(*a);
	var.temp->next->prev = NULL;
	(*a)->prev = var.temp->next;
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
	var.temp->next->prev = NULL;
	(*b)->prev = var.temp->next;
	var.temp->next->next = *b;
	*b = var.temp->next;
	var.temp->next = NULL;
	var.temp = NULL;
}

void ss(t_list **a,t_list **b) //--ss-- sa and sb
{
	sa(a);
	if(*b != NULL)
		sb(b);
}

void rr(t_list **a,t_list **b) //---rr :  ra and rb----////
{
	ra(a);
	if(*b != NULL)
		rb(b);
}