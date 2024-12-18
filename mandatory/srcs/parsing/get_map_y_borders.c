/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_y_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 05:58:06 by athiebau          #+#    #+#             */
/*   Updated: 2024/05/15 16:51:39 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	is_empty_column(char **str, int j, int last)
{
	int	i;

	i = -1;
	while (++i < last - 1)
	{
		if (str[i][j] != ' ')
			return (false);
	}
	return (true);
}

static bool	is_a_column_wall(char **str, int j, int last)
{
	int	i;

	i = -1;
	if (j < 0)
		j = 0;
	while (++i < last - 1)
	{
		if (str[i][j] != '1' && str[i][j] != ' ')
			return (false);
	}
	return (true);
}

bool	check_y_borders(char **str, int last_x, int last_y)
{
	int	i;

	i = -1;
	while (++i < last_y - 1)
	{
		if (str[i][0] != ' ' && str[i][0] != '1')
			return (false);
		if (str[i][last_x - 1] != ' ' && str[i][last_x - 1] != '1')
			return (false);
	}
	i = -1;
	while (++i < last_x - 1)
	{
		if (is_empty_column(str, i, last_y) && (!is_a_column_wall(str, i - 1,
					last_y) || !is_a_column_wall(str, i + 1, last_y)))
			return (false);
	}
	return (true);
}
