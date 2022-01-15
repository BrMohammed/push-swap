# include "push-swap.h"

int main(int argc , char **argv)
{
    int i;
    t_list *a;
    t_list *b;
    t_list *new;

    i = 1;
    if (argc > 2)
    {
        //b = ft_lstnew('\0');
        while (argv[i])
        {
            new = ft_lstnew(ft_atoi(argv[i]));
            ft_lstadd_back(&a,new);
            ft_lstadd_back(&b,new);
            i++;
        }
    
    i--;
    
    if(ft_strcmp(argv[i],"sa") == 0) //sa
    {
        b = ft_lstnew(a->content);
        a->content = a->next->content;
        a->next->content = b->content;
        b = ft_lstnew('\0');
    }
    
    if(ft_strcmp(argv[i],"pb") == 0) //pb
    {
        b->content = a->content;
        a = a->next;
    }

    i = 0;
   //  if( b->content != '\0')
   // {
   //     printf("%d %d\n" ,a->content,b->content);
   //     a = a->next;
   // }  
    while (a)
    {
        printf("%d " , a->content);
        printf("%d\n" ,b->content);
        a = a->next;
        b = b->next;
     /*   if( b->next != NULL)
        {
            printf("%d\n" ,b->content);
            b = b->next;
        }   
        else
            printf("n\n"); */
    }
  
        
    }
  
    return(0);
}