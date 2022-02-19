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
			if(ft_atoi(argv[i]) == -405)
			{
				write(1,"Error\n",6);
				exit(2);
			}
			new = ft_lstnew(ft_atoi(argv[i]));
			ft_lstadd_back(&a,new);
			i++;
		}
		if(check_double(a) == -1)
		{
			write(1,"Error\n",6);
			exit(2);
		}
		tempa = a;
		i = 0;
		/////////calcule the length ////////
		while(tempa)
		{
			tempa = tempa->next;
			i++;
		}
		// while(g < (i / 2))
		// {
		// 	pb(&a,&b);
		// 	write(1,"pb\n",3);
		// 	g++;
		// } 5 10 8 20 1 3 4 9 ---- 5 8 9 2 20 ---** 5 6 7 22 11
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
				printf("pivot..%d\n" ,mediantemp->content);
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
				temp = temp->next;
			}
			temp = mediantemp;
			while(temp)
			{
				if(temp->next != NULL)
				{
					if(temp->content > temp->next->content )
					{
						//tempa = a;
						//tempa = ft_lstlast(a);
						while(a->content < mediantemp->content )
						{
							pb(&a,&b);
							write(1,"pb\n",3);
							moves++;
							tempa = a;
							temp = a;
						}
						//break; 
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
							printf("pivotD..%d\n" ,mediantemp->content);
							if(b->content < b->next->content)
							{
								sb(&b);
								write(1,"sb\n",3);
								moves++;
							}
							tempb = ft_lstlast(b);
							if(mediantemp->content < tempb->content)
							{
								rrb(&b);
								write(1,"rra\n",4);
								moves++;
								temp = b;
							}
							tempb = ft_lstlast(b);
							if(b->content < tempb->content && b->content < mediantemp->content)
							{
								rb(&b);
								write(1,"rb\n",3);
								moves++;
								temp = b;
							}
							temp = temp->next;
						}
				}	
			}
			temp = b;
			if(tempa->next == NULL && b)
			{
				while(temp && b)
				{
					pa(&a,&b);
					write(1,"pa\n",3);
					temp = temp->next;
					moves++;
					tempa = a;
				}
			}
			tempa = tempa->next;
		}
		
		///////////////////------showing------////////////////////
		i = 0;
		tempa = a;
		mediantemp = b;
		while (tempa || mediantemp)
		{
			if (tempa == NULL)
			{
				printf(" -");
			}
			else
			{ 
		   		printf("%d-" ,tempa->content);
		   		tempa = tempa->next;
			}
		 	if (mediantemp == NULL)
			{
				printf(" \n");
			}
			else if( mediantemp->content )
			{ 
		   		printf("%d\n" ,mediantemp->content);
		   		mediantemp = mediantemp->next;
			}
			i++;
		}
	}
	else
		write(1,"Error\n",6);
	printf("*Moves* : %d\n" , moves);
	return(0);
}