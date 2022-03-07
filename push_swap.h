/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:38:09 by brmohamm          #+#    #+#             */
/*   Updated: 2022/03/03 14:38:09 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_variabl
{
	t_list	*temp;
	int		f;
	int		g;
	int		y;
	int		z;
	int		pp;
	int		nn;
	int		bb;
	int		cc;
	int		gg;

}	t_variabl;

int		ft_atoi(char *str);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_strcmp( const char *s1, const char *s2);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast_beforlast(t_list *lst);
int		check_double(t_list *a);
int		check_order(t_list *a);
void	insert_the_index(t_list *a, int i);
int		ft_isdigit(char *c);
void	less_than_5(t_list **a, t_list **b, int f);
void	more_than_5(t_list **a, t_list **b, t_variabl *var);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup( const char *src );
size_t	ft_strlen(const char *str);
int		ft_strchr(const char *str, int c);

void	sa(t_list **a, int fals);
void	sb(t_list **b, int fals);
void	pb(t_list **a, t_list **b, int fals);
void	pa(t_list **a, t_list **b, int fals);
void	ra(t_list **a, int fals);
void	rb(t_list **b, int fals);
void	rra(t_list **a, int fals);
void	rrb(t_list **b, int fals);
void	ss(t_list **a, t_list **b, int fals);
void	rr(t_list **a, t_list **b, int fals);
void	rrr(t_list **a, t_list **b, int fals);

void	print_stack(t_list *list);

#endif
