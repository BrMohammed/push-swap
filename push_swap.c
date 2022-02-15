# include "push_swap.h"

int main(int argc , char **argv)
{
	int i;
	int g = 0;
	t_list *a;
	t_list *b;
	t_list *new;
	t_list *temp;
	t_list *tempa;
	t_list *tempb;

	i = 1;
	b = NULL;
	temp = NULL;
	if (argc > 2)
	{
		while (argv[i])
		{
			if(ft_atoi(argv[i]) == -405)
			{
				write(1,"Error\n",6);
				exit(2);
			}
			new = ft_lstnew(ft_atoi(argv[i]));
			ft_lstadd_back(&a,new);
			i++;
		}
		i--;
		tempa = a;
		i = 0;
		while(tempa)
		{
			tempa = tempa->next;
			i++;
		}
		while(g < (i / 2))
		{
			pb(&a,&b);
			write(1,"pb\n",3);
			g++;
		}
		tempa = a;
		while(tempa)
		{
			tempa = ft_lstlast(a);
			if(a->content > tempa->content)
			{
				rra(&a);
				write(1,"rra\n",4);
				tempa = a;
			}
			if(a->content > a->next->content)
			{
				sa(&a);
				write(1,"sa\n",3);
				tempa = a;
			}
			temp = ft_lstlast_beforlast(a);
			if(temp->content > temp->next->content)
			{
				rra(&a);
				write(1,"rra\n",4);
				tempa = a;
			}
			tempa = tempa->next;
		}

		if(ft_strcmp(argv[i],"sa") == 0) //sa revest the ferst and the seconde in 'a'
		{
			sa(&a);
		}

		if(ft_strcmp(argv[i],"sb") == 0 && b != NULL) //sa revest the ferst and the seconde in 'b'
		{
			sb(&b);
		}

		if(ft_strcmp(argv[i],"ss") == 0)//--ss-- sa and sb
		{
			ss(&a,&b);
		}

		if(ft_strcmp(argv[i],"pb") == 0) //pb send the first one in 'a' to the last in 'b'
		{
			pb(&a,&b);
		}

		if(ft_strcmp(argv[i],"pa") == 0 && b != NULL) //pa send the first one in 'b' to the last in 'a'
		{
			pa(&a,&b);
		}

		if(ft_strcmp(argv[i],"ra") == 0) //ra send the first one in 'a' to the last
		{
			ra(&a);
		}

		if(ft_strcmp(argv[i],"rb") == 0 && b != NULL) //rb send the first one in 'b' to the last
		{
			rb(&b);
		}

		if(ft_strcmp(argv[i],"rr") == 0) //---rr :  ra and rb----////
		{
			rr(&a,&b);
		}

		if(ft_strcmp(argv[i],"rra") == 0) //rra send the last one in 'a' to the first
		{
			rra(&a);
		}

		if(ft_strcmp(argv[i],"rrb") == 0 && b != NULL) //rrb send the last one in 'b' to the first
		{
			rrb(&b);
		}

		///////////////////------showing------////////////////////
		i = 0;
		tempa = a;
		tempb = b;
		while (tempa || tempb)
		{
			if (tempa == NULL)
			{
				printf("-");
			}
			else if( tempa->content )
			{ 
		   		printf("%d-" ,tempa->content);
		   		tempa = tempa->next;
			}
		 	if (tempb == NULL)
			{
				printf(" \n");
			}
			else if( tempb->content )
			{ 
		   		printf("%d\n" ,tempb->content);
		   		tempb = tempb->next;
			}
			i++;
		}
	}
	else
		write(1,"Error\n",6);
	return(0);
}