/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mcgic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:40:05 by athiebau          #+#    #+#             */
/*   Updated: 2024/05/10 17:40:07 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_countwords(const char *s, char c)
{
	int	c_wd;
	int	i;

	c_wd = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			c_wd++;
			i++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (c_wd);
}

static void	*ft_free_strs(char **strs, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		mcgic(strs[i], 0, FREE);
		i++;
	}
	mcgic(strs, 0, FREE);
	return (NULL);
}

static char	**ft_split_strs(const char *s, char c, char **strs, int c_wd)
{
	int	j;
	int	c_lt;

	j = -1;
	while (*s && ++j < c_wd)
	{
		c_lt = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			c_lt++;
			s++;
		}
		if (c_lt > 0)
		{
			strs[j] = mcgic(NULL, sizeof(char) * (c_lt + 1), MLC);
			if (strs[j] == NULL)
				return (ft_free_strs(strs, j));
			ft_strlcpy(strs[j], s - c_lt, c_lt + 1);
		}
	}
	return (strs);
}

char	**ft_split_mcgic(char const *s, char c)
{
	int		c_wd;
	char	**strs;

	if (!s)
		return (NULL);
	if (!c && s[0] == '\0')
		c_wd = 0;
	else if (!c)
		c_wd = 1;
	else
		c_wd = ft_countwords(s, c);
	strs = mcgic(NULL, sizeof(char *) * (c_wd + 1), MLC);
	if (strs == NULL)
		return (NULL);
	if (ft_split_strs(s, c, strs, c_wd) == NULL)
		return (NULL);
	strs[c_wd] = NULL;
	return (strs);
}
