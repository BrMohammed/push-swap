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