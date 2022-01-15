# include "push-swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*index;

	index = (t_list *)malloc(sizeof(t_list));
	if (!index)
		return (NULL);
	index->content = content;
	index->next = NULL;
	index->prev = NULL;
	return (index);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
			
		}	
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst)
	{	
		temp = ft_lstlast(*lst);
		if(*lst != NULL)
			temp->prev = *lst;
		temp->next = new;
	}
	else
		*lst = new;
}