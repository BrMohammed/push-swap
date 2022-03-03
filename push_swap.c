# include "push_swap.h"

void print_stack(t_list *list)
{
	t_list *tmp;
	tmp = list;
	printf("list: ============================\n");
	while (tmp)
	{
		printf("%d => ", tmp->content);
		tmp = tmp->next;
	}
	printf("=================================\n");
}

int main(int argc , char **argv)
{
	int i;
	int moves;
	int g;
	int x;
	int t;
	int y;
	int z;
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
	z = 0;
	moves = 0;

	if (argc > 2)
	{
		while (argv[i])
		{
			if(ft_isdigit(argv[i]) == 1)
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
		int f = 0;
		while(tempa)
		{
			tempa = tempa->next;
			f++;
		}
		insert_the_index(a,f);
		if(f <= 5)
		{

			//temp = a;
			if(f > 3)
			{
				z = 1;
				while(z < 3)
				{
					while(a->index != z)
					{
						ra(&a);
						write(1,"ra\n",3);
						moves++;
					}
					pb(&a,&b);
					write(1,"pb\n",3);
					moves++;
					z++;
				}
			}
			temp = a;
			while(temp)
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
					// if(temp->next != NULL)
					// {
					// 	while(b)
					// 	{
					// 		pa(&a,&b);
					// 		write(1,"pa\n",3);
					// 		moves++;
					// 	}
					// }
					temp = temp->next;
				}
			}
			while(b)
			{
				pa(&a,&b);
				write(1,"pa\n",3);
				moves++;
			}
			//print_stack(a);
		//	print_stack(a);
			exit(0);
			

		}
		else if(f <= 100)
			z = f/7;
		else
			z = f/14;
		
		tempa = a;
		tempb = b;
		g = 0;
		y = z;
		int nn = z;
		int bb = z;
		while(a)
		{
			while(g < y)
			{
				if(a)
				{
					while(a->index > y)
					{
						temp = a;
						int pp = 0;
						while(temp->next)
						{
							temp = temp->next;
							pp++;
						}
						if((a->index > f - (nn + bb ) && a->index <= f - bb) || (pp < 17))
						{
							pb(&a,&b);
							write(1,"pb\n",3);
							moves++;
							rb(&b);
							write(1,"rb\n",3);
							moves++;
						}
						else
						{
							ra(&a);
							write(1,"ra\n",3);
							moves++;
						}
					}
					pb(&a,&b);
					write(1,"pb\n",3);
					moves++;
				}
				g++;
				if (g == nn)
				{
					bb = 0;
				}
			}
			y = y + z;
		}
		t = f;
		while(t > 0)
		{
			temp = b;
			while(temp->index != t &&  temp->next != NULL)
			{
				temp = temp->next;
			}
			mediantemp = b;
			g = 0;
			while(mediantemp)
			{
				mediantemp = mediantemp->next;
				g++;
			}
			mediantemp = b;
			x = 0;
			while(mediantemp)
			{
				if(temp->index == mediantemp->index)
					break;
				mediantemp = mediantemp->next;
				x++;
			}
			if(x > g/2)
			{
				while(temp->index != b->index)
				{
						rrb(&b);
						write(1,"rrb\n",4);
						moves++;
				}
			}
			else
			{
				while(temp->index != b->index)
				{
					rb(&b);
					write(1,"rb\n",3);
					moves++;
				}
			}
			if(temp->index == b->index)
			{
				pa(&a,&b);
				write(1,"pa\n",3);
				moves++;
			}
			t--;
		}
		

		///////////////------showing------////////////////////
		// i = 0;
		// tempa = a;
		// mediantemp = b;
		// printf("---------------------------------\nA\t\t\tB\n\n");
		// while (tempa || mediantemp)
		// {
		// 	if (tempa == NULL)
		// 	{
		// 		printf(" ** ");
		// 	}
		// 	else
		// 	{ 
		//    		printf("%d : %d" ,tempa->content,tempa->index);
		//    		tempa = tempa->next;
		// 	}
		//  	if (mediantemp == NULL)
		// 	{
		// 		printf(" \n");
		// 	}
		// 	else if( mediantemp->content )
		// 	{ 
		//    		printf("\t\t*** %d : %d\n" ,mediantemp->content,mediantemp->index);
		//    		mediantemp = mediantemp->next;
		// 	}
		// 	i++;
		// }
	// 	// i = 0;
	// 	// tempa = a;
	// 	// while (tempa)
	// 	// {
	// 	//    	printf("%d : %d\n" ,tempa->content,tempa->index);
	// 	//    	tempa = tempa->next;
	// 	// 	i++;
	// 	// }
	 }
	 else
	 	write(1,"Error\n",6);
	//printf("*Moves* : %d\n" , moves);
	return(0);
}