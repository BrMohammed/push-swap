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

int	ft_isdigit01(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
int	ft_isdigit(char *c)
{
	int n = 0;
	while(c[n])
	{
		if(ft_isdigit01(c[n]) == 0)
			return(1);
		n++;
	}
	return(0);
}
