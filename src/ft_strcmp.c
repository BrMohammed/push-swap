/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 02:58:52 by brmohamm          #+#    #+#             */
/*   Updated: 2022/03/04 03:12:51 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp( const char *s1, const char *s2)
{
	size_t	m;

	m = 0;
	if (s1 == s2)
		return (0);
	while (s1[m] != '\0' && s2[m] != '\0')
	{
		if (s1[m] != s2[m])
		{
			return (((unsigned char *)s1)[m] - ((unsigned char *)s2)[m]);
		}
		m++;
	}
	if ((s1[m] == '\0' && s2[m] != '0')
		|| (s2[m] == '\0' && s1[m] != '\0'))
		return (((unsigned char *)s1)[m] - ((unsigned char *)s2)[m]);
	return (0);
}
