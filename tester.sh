# !/bin/bash
make; ./push_swap 

8 6 5 7 2

6 9 5 8 4 

6 7 3 8 4


10 1 4 3



***6 7 3 1***
	while(tempa)
		{
			tempa = ft_lstlast(a);
			temp = a;
			while(temp)
			{
				mediantemp = a;
				while(mediantemp->content < mediantemp->next->content)
				{
					mediantemp = mediantemp->next;
					if(mediantemp->next == NULL)
						break;
				}
				printf("pivot..%d\n" ,mediantemp->content);
				if(mediantemp->content > tempa->content || a->content > tempa->content)
				{
					rra(&a);
					write(1,"rra\n",4);
					moves++;
					//temp = a;
				}
				// if(a->content > a->next->content)
				// {
				// 	sa(&a);
				// 	write(1,"sa\n",3);
				// 	moves++;
				// 	temp = a;
				// }
				if(a->content > tempa->content)
				{

					// if(tempa->content > mediantemp->content)
					// {
					// 	ra(&a);
					// 	write(1,"ra\n",3);
					// 	moves++;
					// 	//temp = a;
					// }
					// else
					// {
						rra(&a);
						write(1,"rra\n",4);
						moves++;
						//temp = a;
					// }
					
				}
				if(a->content > a->next->content)
				{
					sa(&a);
					write(1,"sa\n",3);
					moves++;
					//temp = a;
				}
				temp = temp->next;
			}