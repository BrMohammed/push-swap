# include "push_swap.h"

int main(int argc , char **argv)
{
	int i;
	t_list *a;
	t_list *b;
	t_list *new;
	t_list *temp;

	i = 1;
	b = NULL;
	temp = NULL;
	if (argc > 2 )
	{
		while (argv[i] && (argc - i - 1) != 0)
		{
			new = ft_lstnew(ft_atoi(argv[i]));
			ft_lstadd_back(&a,new);
			i++;
		}

		if(ft_strcmp(argv[i],"sa") == 0) //sa revest the ferst and the seconde in 'a'
		{
			temp = a;
			a = a->next;
			temp->next = a->next;
			a->next = temp;
			free (temp);
			temp = NULL;
		}

		if(ft_strcmp(argv[i],"sb") == 0 && b != NULL) //sa revest the ferst and the seconde in 'b'
		{
			
			temp = b;
			b = b->next;
			temp->next = b->next;
			b->next = temp;
			temp = NULL;
		}
		
		//--ss-- sa and sb

		

		if(ft_strcmp(argv[i],"pb") == 0) //pb send the first one in 'a' to the last in 'b'
		{
			temp = a;
			a = a->next;
			temp->next = b;
			b = temp;
			temp = NULL;
		}

		if(ft_strcmp(argv[i],"pa") == 0 && b != NULL) //pa send the first one in 'b' to the last in 'a'
		{
			temp = b;
			b = b->next;
			temp->next = a;
			a = temp;
			temp = NULL;
		}

		///////////////////------showing------////////////////////
		i = 0;
		while (a)
		{
			printf("%d " , a->content);
			a = a->next;
		 	if (b == NULL)
			{
				printf(" \n");
			}
			else if( b->content )
			{ 
		   		printf("%d\n" ,b->content);
		   		b = b->next;
			}
			i++;
		}
	}
	return(0);
}