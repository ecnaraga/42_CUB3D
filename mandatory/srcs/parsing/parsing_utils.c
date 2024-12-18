/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:15:33 by galambey          #+#    #+#             */
/*   Updated: 2024/04/02 15:26:24 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_rstrncmp(const char *s1, const char *s2, int n)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	while (n > 0)
	{
		if (i == -1 && j == -1)
			return (0);
		if (i == -1 && j >= 0)
			return (-s2[j]);
		if (j == -1 && i >= 0)
			return (s1[i]);
		if (s1[i] != s2[j])
			return (s1[i] - s2[j]);
		n--;
		i--;
		j--;
	}
	return (0);
}

bool	ft_isspace_nonewline(char c)
{
	if (c == ' ' || c == '\t' || (c >= '\v' && c <= '\r'))
		return (TRUE);
	return (FALSE);
}
