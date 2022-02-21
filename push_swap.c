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
	// t_list *tempb;

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
		int g = 1;
		int t = 0;
		tempa = a;
		while(tempa)
		{
			while(t < i)
			{
				temp = a;
				while(temp->index != g &&  temp->next != NULL)
				{
					temp = temp->next;
				}
				while(temp->content != a->content)
				{
					pb(&a,&b);
				}
				if(temp->content == a->content)
				{
					ra(&a);
				}
				t++;
			}
			t = 0;
			g++;
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
		   			printf("%d : %d\n" ,tempa->content,tempa->index);
		   		tempa = tempa->next;
			}
		 	if (mediantemp == NULL)
			{
				printf(" \n");
			}
			else if( mediantemp->content )
			{ 
		   		printf("%d : %d\n" ,mediantemp->content,mediantemp->index);
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