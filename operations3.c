# include "push_swap.h"

void rrr(t_list **a,t_list **b) //-rrr : rra and rrb at the same time.
{
	rra(a);
	if(*b != NULL)
		rrb(b);
}

