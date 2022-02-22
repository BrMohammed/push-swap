# include "push_swap.h"



int main(int argc , char **argv)
{
	int i;
	int moves;
	int t;
	int g;
	int x;
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
		insert_the_index(a,i);
		//int g = 1;
		t = 0;
		while(t < i)
		{
			temp = a;
			while(temp->index != t &&  temp->next != NULL)
			{
				temp = temp->next;
			}
			if(temp->next == NULL && b)
			{
				temp = b;
				while(temp->index != t &&  temp->next != NULL)
				{
					temp = temp->next;
				}
			}
			if(b)
			{
				tempb = b;
				while(tempb)
				{
					if(temp->index == tempb->index)
					{
						temp->moved = 0;
						break;
					}
					tempb =tempb->next;
				}
			}
			if(temp->moved == -1)
			{
				if(temp->next != NULL)
				{
					while(temp->index != a->index)
					{	
						pb(&a,&b);
						write(1,"pb\n",3);
						moves++;
					}
					if(temp->index == a->index)
					{
						ra(&a);
						write(1,"ra\n",3);
						moves++;
					}
				}
			}
			else
			{
				mediantemp = b;
				g =0;
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
					ra(&a);
					write(1,"ra\n",3);
					moves++;
				}
			}
			t++;
		}
		/////////////////------showing------////////////////////
		i = 0;
		tempa = a;
		mediantemp = b;
		printf("---------------------------------\nA\t\t\tB\n\n");
		while (tempa || mediantemp)
		{
			if (tempa == NULL)
			{
				printf(" ** ");
			}
			else
			{ 
		   		printf("%d : %d -> %d " ,tempa->content,tempa->index,tempa->moved);
		   		tempa = tempa->next;
			}
		 	if (mediantemp == NULL)
			{
				printf(" \n");
			}
			else if( mediantemp->content )
			{ 
		   		printf("\t\t*** %d : %d -> %d\n" ,mediantemp->content,mediantemp->index,mediantemp->moved);
		   		mediantemp = mediantemp->next;
			}
			i++;
		}
		// i = 0;
		// tempa = a;
		// while (tempa)
		// {
		//    	printf("%d : %d\n" ,tempa->content,tempa->index);
		//    	tempa = tempa->next;
		// 	i++;
		// }
	}
	else
		write(1,"Error\n",6);
	printf("*Moves* : %d\n" , moves);
	return(0);
}