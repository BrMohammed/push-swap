# include "push_swap.h"

int main(int argc , char **argv)
{
	int i;
	//int g;
	t_list *a;
	t_list *b;
	t_list *new;
	t_list *temp;
	t_list *tempa;
	t_list *mediantemp;

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
		// } 5 10 8 20 1 3 4 9 ---- 5 8 9 2 20
		/////////////////////////////////////


		tempa = a;
		while(tempa)
		{
			mediantemp = a;
			tempa = ft_lstlast(a);
			if(a->content > a->next->content)
			{
				sa(&a);
				write(1,"sa\n",3);
			}
			while(mediantemp->content < mediantemp->next->content)
			{
				mediantemp = mediantemp->next;
			}
			printf("pivot..%d\n" ,mediantemp->content);
			if(mediantemp->content > tempa->content || a->content > tempa->content)
			{
				rra(&a);
				write(1,"rra\n",4);
			}
			temp = mediantemp;
			while(temp)
			{
				if(temp->content > temp->next->content)
				{
					tempa = a;
					while(tempa->content != mediantemp->content)
					{
						pb(&a,&b);
						write(1,"pb\n",3);
						tempa = a;
					}
					break;
				}
				temp = temp->next;
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
				printf("-");
			}
			else if( tempa->content )
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
	return(0);
}