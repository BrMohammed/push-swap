# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int	ft_atoi(char *str);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int	ft_strcmp( const char *s1, const char *s2);


#endif