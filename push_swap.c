# include "push_swap.h"

int main(int argc , char **argv)
{
	int i;
	t_list *a;
	t_list *b;
	t_list *new;
	t_list *temp;
	t_list *tempa;
	t_list *tempb;

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
			sa(&a);
		}

		if(ft_strcmp(argv[i],"sb") == 0 && b != NULL) //sa revest the ferst and the seconde in 'b'
		{
			sa(&b);
		}
		
		//--ss-- sa and sb

		if(ft_strcmp(argv[i],"pb") == 0) //pb send the first one in 'a' to the last in 'b'
		{
			pb(&a,&b);
		}

		if(ft_strcmp(argv[i],"pa") == 0 && b != NULL) //pa send the first one in 'b' to the last in 'a'
		{
			pa(&a,&b);
		}

		if(ft_strcmp(argv[i],"ra") == 0) //ra send the first one in 'a' to the last
		{
			ra(&a);
		}

		if(ft_strcmp(argv[i],"rb") == 0 && b != NULL) //rb send the first one in 'b' to the last
		{
			rb(&b);
		}

		///////---rr :  ra and rb----////

		if(ft_strcmp(argv[i],"rra") == 0) //rra send the last one in 'a' to the first
		{
			rra(&a);
		}

		if(ft_strcmp(argv[i],"rrb") == 0 && b != NULL) //rrb send the last one in 'b' to the first
		{
			rrb(&b);
		}

		////////////-rrr : rra and rrb at the same time.----///////

		///////////////////------showing------////////////////////
		i = 0;
		tempa = a;
		tempb = b;
		while (tempa)
		{
			printf("%d " , tempa->content);
			tempa = tempa->next;
		 	if (tempb == NULL)
			{
				printf(" \n");
			}
			else if( tempb->content )
			{ 
		   		printf("%d\n" ,tempb->content);
		   		tempb = tempb->next;
			}
			i++;
		}
	}
	return(0);
}