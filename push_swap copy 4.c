# include "push_swap.h"

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
		int f = 0;
		while(tempa)
		{
			tempa = tempa->next;
			f++;
		}
		if(f <= 5)
		{
			z = f/1;
		}
		else if(f <= 100)
			z = f/7;
		else
			z = f/14;
		insert_the_index(a,f);
		tempa = a;
		tempb = b;
		g = 0;
		y = z;
		int nn = z;
		int bb = z;
		int gg = 0;
		while(a)
		{
			while(g < y)
			{
				if(a)
				{
					while(a->index > y)
					{
						if(a->index > f - (nn + bb) && a->index <= f - bb)
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
				gg++;
				if (gg == nn)
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
	// 	i = 0;
	// 	tempa = a;
	// 	mediantemp = b;
	// 	printf("---------------------------------\nA\t\t\tB\n\n");
	// 	while (tempa || mediantemp)
	// 	{
	// 		if (tempa == NULL)
	// 		{
	// 			printf(" ** ");
	// 		}
	// 		else
	// 		{ 
	// 	   		printf("%d : %d" ,tempa->content,tempa->index);
	// 	   		tempa = tempa->next;
	// 		}
	// 	 	if (mediantemp == NULL)
	// 		{
	// 			printf(" \n");
	// 		}
	// 		else if( mediantemp->content )
	// 		{ 
	// 	   		printf("\t\t*** %d : %d\n" ,mediantemp->content,mediantemp->index);
	// 	   		mediantemp = mediantemp->next;
	// 		}
	// 		i++;
	// 	}
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
	// printf("*Moves* : %d\n" , moves);
	return(0);
}