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
		// }
		/////////////////////////////////////

		
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