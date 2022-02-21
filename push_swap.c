# include "push_swap.h"



int main(int argc , char **argv)
{
	int i;
	int moves;
	int t;
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
		tempa = a;
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
				while(tempb->next != NULL)
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
				// if(a->next->index == temp->index)
				// {
				// 	sa(&a);
				// }
				while(temp->index != a->index)
				{
					pb(&a,&b);
				}
				if(temp->index == a->index)
				{
					ra(&a);
				}
			}
			else
			{
				// if(b->next->content == temp->content)
				// {
				// 	sb(&b);
				// }
				while(temp->index != b->index)
				{
					rrb(&b);
				}
				if(temp->index == b->index)
				{
					pa(&a,&b);
					ra(&a);
				}
			}
			t++;
		}
		/////////////////------showing------////////////////////
		i = 0;
		tempa = a;
		mediantemp = b;
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
		   		printf("*** %d : %d -> %d\n" ,mediantemp->content,mediantemp->index,mediantemp->moved);
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