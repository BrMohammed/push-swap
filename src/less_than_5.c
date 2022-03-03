# include "../push_swap.h"

void if_more_than_3(int z,t_list **a, t_list **b)
{
    z = 1;
    while(z < 3)
    {
        while((*a)->index != z)
        {
            ra(a);
            write(1,"ra\n",3);
        }
        pb(a,b);
        write(1,"pb\n",3);
        z++;
    }
}

t_list *middle(t_list *mediantemp, t_list *tempa,t_list *temp,t_list **a)
{
     while(mediantemp->content < mediantemp->next->content )
    {
        mediantemp = mediantemp->next;
        if(mediantemp->next == NULL)
            break;
    }
    if((*a)->content > (*a)->next->content)
    {
        sa(a);
        write(1,"sa\n",3);
    }
    tempa = ft_lstlast((*a));
    if(mediantemp->content > tempa->content)
    {
        rra(a);
        write(1,"rra\n",4);
        temp = (*a) ;
    }
    tempa = ft_lstlast((*a));
    if((*a)->content > tempa->content && (*a)->content > mediantemp->content)
    {
        ra(a);
        write(1,"ra\n",3);
        temp = (*a);
    }
    return(temp);
}

void less_than_5(t_list **a, t_list **b,int f)
{
    int z;
    t_list *temp;
    t_list *tempa;
    t_list *mediantemp;

    z = 0;
    if(f > 3)
        if_more_than_3(z,a,b);
    temp = *a;
    while(temp)
    {
        tempa = ft_lstlast(*a);
        temp = *a;
        while(temp)
        {
           temp = ft_lstlast(*a);
            mediantemp = *a;
            temp = middle(mediantemp,tempa,temp,a);
            temp = temp->next;
        //     while(mediantemp->content < mediantemp->next->content )
        //     {
        //         mediantemp = mediantemp->next;
        //         if(mediantemp->next == NULL)
        //             break;
        //     }
        //     if(a->content > a->next->content)
        //     {
        //         sa(&a);
        //         write(1,"sa\n",3);
        //     }
        //     tempa = ft_lstlast(a);
        //     if(mediantemp->content > tempa->content)
        //     {
        //         rra(&a);
        //         write(1,"rra\n",4);
        //         temp = a;
        //     }
        //     tempa = ft_lstlast(a);
        //     if(a->content > tempa->content && a->content > mediantemp->content)
        //     {
        //         ra(&a);
        //         write(1,"ra\n",3);
        //         temp = a;
        //     }
        //     temp = temp->next;
        }
    }
    while(*b)
    {
        pa(a,b);
        write(1,"pa\n",3);
    }
    exit(0);
}