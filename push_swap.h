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
	int			index;
	int			moved;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

int	ft_atoi(char *str);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int	ft_strcmp( const char *s1, const char *s2);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast_beforlast(t_list *lst);
int	check_double(t_list *a);
void insert_the_index(t_list *a,int i);
int	ft_isdigit(char *c);


void sa(t_list **a);
void sb(t_list **b);
void pb(t_list **a, t_list **b);
void pa(t_list **a, t_list **b);
void ra(t_list **a);
void rb(t_list **b);
void rra(t_list **a);
void rrb(t_list **b);
void ss(t_list **a,t_list **b);
void rr(t_list **a,t_list **b);
void rrr(t_list **a,t_list **b);

typedef struct s_variabl
{
	t_list *temp;

} t_variabl;

#endif