# include "../push_swap.h"

void insert_the_index(t_list *a,int i)
{
    t_list *indextemp;
    t_list *tempa;
    int g;
    int t;

    g = i;
	t = 0;
	while(g > 0)
	{
		
		tempa = a;
		while(tempa)
		{
			if(tempa->index == -1)
			{
				indextemp = tempa;
				break;
			}
			tempa = tempa->next;
		}
        tempa = a;
		while(t < i)
		{
			if(tempa->content > indextemp->content && tempa->index == -1)
				indextemp = tempa;
			if(tempa)
				tempa = tempa->next;
			t++;
		}
		if(indextemp->content != -1)
			indextemp->index = g;
		t = 0;
		g--;
	}
}