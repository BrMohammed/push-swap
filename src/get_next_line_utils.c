/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:56:13 by brmohamm          #+#    #+#             */
/*   Updated: 2022/03/07 00:15:25 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strdup( const char *src )
{
	char	*c;
	int		n;

	n = 0;
	while (src[n] != '\0')
		n++;
	c = malloc(n + 1);
	if (c == 0)
		return (NULL);
	n = 0;
	while (src[n] != '\0')
	{
		c[n] = src[n];
		n++;
	}
	c[n] = '\0';
	return (c);
}

int	ft_strchr( const char *str, int c )
{
	unsigned char	chr;
	char			*st;
	int				n;

	chr = c;
	st = (char *)str;
	if (!str)
		return (0);
	n = 0;
	while (st[n] != '\0')
	{
		if (st[n] == chr)
		{
			return (1);
		}
		n++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}
