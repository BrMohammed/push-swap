# include "../push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*index;

	index = (t_list *)malloc(sizeof(t_list));
	if (!index)
		return (NULL);
	index->content = content;
	index->index = -1;
	index->moved = -1;
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

t_list	*ft_lstlast_beforlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next->next != NULL)
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
		new->prev = temp;
		temp->next = new;
		
	}
	else
		*lst = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *(lst);
	*lst = new;
}
