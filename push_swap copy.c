# include "push_swap.h"

int main(int argc , char **argv)
{
	int i;
	int moves;
	t_list *a;
	t_list *b;
	t_list *new;
	t_list *temp;
	t_list *tempa;
	t_list *mediantemp;
	t_list *tempb;

	i = 1;
	b = NULL;
	temp = NULL;
	moves = 0;
	if (argc > 2)
	{
		while (argv[i])
		{
			new = ft_lstnew(ft_atoi(argv[i]));
			ft_lstadd_back(&a,new);
			i++;
		}
		tempa = a;
		i = 0;
		/////////calcule the length ////////
		while(tempa)
		{
			tempa = tempa->next;
			i++;
		}
		/////////////////////////////////////

		tempa = a;
		while(tempa)
		{
			tempa = ft_lstlast(a);
			temp = a;
			while(temp)
			{
				temp = ft_lstlast(a);
				mediantemp = a;
				while(mediantemp->content < mediantemp->next->content )
				{
					mediantemp = mediantemp->next;
					if(mediantemp->next == NULL)
						break;
				}
				//printf("pivot..%d\n" ,mediantemp->content);
				if(a->content > a->next->content)
				{
					sa(&a);
					write(1,"sa\n",3);
					moves++;
				}
				tempa = ft_lstlast(a);
				if(mediantemp->content > tempa->content)
				{
					rra(&a);
					write(1,"rra\n",4);
					moves++;
					temp = a;
				}
				tempa = ft_lstlast(a);
				if(a->content > tempa->content && a->content > mediantemp->content)
				{
					ra(&a);
					write(1,"ra\n",3);
					moves++;
					temp = a;
				}
				if(mediantemp->next != NULL)
				{
					if(mediantemp->content > mediantemp->next->content )
					{
						pb(&a,&b);
						write(1,"pb\n",3);
						moves++;
						temp = a;
					}
				}
				temp = temp->next;
			}
			temp = b;
			if(b)
			{
				if(b->next != NULL)
				{
						tempb = ft_lstlast(b);
						temp = b;
						while(temp)
						{
							temp = ft_lstlast(b);
							mediantemp = b;
							while(mediantemp->content > mediantemp->next->content )
							{
								mediantemp = mediantemp->next;
								if(mediantemp->next == NULL)
								break;
							}
							//printf("pivotD..%d\n" ,mediantemp->content);
							if(b->content < b->next->content)
							{
								sb(&b);
								write(1,"sb\n",3);
								moves++;
							}
							
							if(mediantemp->content < tempb->content)
							{
								rrb(&b);
								write(1,"rra\n",4);
								moves++;
								temp = b;
								tempa = a;
							}
							tempb = ft_lstlast(b);
							if(b->content < tempb->content && b->content < mediantemp->content)
							{
								rb(&b);
								write(1,"rb\n",3);
								moves++;
								temp = b;
								tempa = a;
							}
							temp = temp->next;
						}
				}	
			}
			 if((tempa->next == NULL && b))
			{
				pa(&a,&b);
				write(1,"pa\n",3);
				moves++;
				tempa = a;
			}
			tempa = tempa->next;
		}
		
		///////////////////------showing------////////////////////
		// i = 0;
		// tempa = a;
		// mediantemp = b;
		// while (tempa || mediantemp)
		// {
		// 	if (tempa == NULL)
		// 	{
		// 		printf(" -");
		// 	}
		// 	else
		// 	{ 
		//    		printf("%d-" ,tempa->content);
		//    		tempa = tempa->next;
		// 	}
		//  	if (mediantemp == NULL)
		// 	{
		// 		printf(" \n");
		// 	}
		// 	else if( mediantemp->content )
		// 	{ 
		//    		printf("%d\n" ,mediantemp->content);
		//    		mediantemp = mediantemp->next;
		// 	}
		// 	i++;
		// }
	}
	else
		write(1,"Error\n",6);
	//printf("*Moves* : %d\n" , moves);
	return(0);
}