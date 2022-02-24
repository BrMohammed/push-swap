# include "../push_swap.h"

void rrr(t_list **a,t_list **b) //-rrr : rra and rrb at the same time.
{
	rra(a);
	if(*b != NULL)
		rrb(b);
}

int	check_double(t_list *a)
{
	t_list	*temp;

	temp = a;
	while (a)
	{
		if(a->next != NULL)
			temp = temp->next;
		if (a->content == temp->content && a->next != NULL)
			return(-1);
		if(temp->next == NULL)
		{
			a = a->next;
			temp = a;
		}
	}
	return(0);
}