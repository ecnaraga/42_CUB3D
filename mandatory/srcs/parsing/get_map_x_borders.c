/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_x_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 05:57:19 by athiebau          #+#    #+#             */
/*   Updated: 2024/05/14 10:57:50 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	is_empty_line(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ')
			return (false);
	}
	return (true);
}

static bool	is_a_line_wall(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (false);
	while (str[++i])
	{
		if (str[i] != '1' && str[i] != ' ')
			return (false);
	}
	return (true);
}

bool	check_x_borders(char **str, int last)
{
	int	i;

	i = 0;
	if (!is_a_line_wall(str[i]) || !is_a_line_wall(str[last - 1]))
		return (false);
	while (++i < last)
	{
		if (is_empty_line(str[i]) && (!is_a_line_wall(str[i - 1])
				|| !is_a_line_wall(str[i + 1])))
			return (false);
	}
	return (true);
}
