/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:27:06 by athiebau          #+#    #+#             */
/*   Updated: 2024/05/15 17:46:13 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_set_direction(t_cub *cub, char dir)
{
	if (dir == 'N')
		cub->p.pa = 360;
	else if (dir == 'S')
		cub->p.pa = 180;
	else if (dir == 'W')
		cub->p.pa = 270;
	else if (dir == 'E')
		cub->p.pa = 90;
	cub->p.sin_mv = sin(ft_deg_to_rad(cub->p.pa)) * cub->speed;
	cub->p.cos_mv = cos(ft_deg_to_rad(cub->p.pa)) * cub->speed;
}

static bool	check_borders_bis(t_cub *cub, int i, int j)
{
	if (cub->map.map_final[i][j] == 'N'
		|| cub->map.map_final[i][j] == 'S'
		|| cub->map.map_final[i][j] == 'E'
		|| cub->map.map_final[i][j] == 'W')
	{
		cub->p.y_pos = i + 0.5;
		cub->p.x_pos = j + 0.5;
		ft_set_direction(cub, cub->map.map_final[i][j]);
	}
	if (i > 0 && !ft_strchr(ALLOWD_BRD, cub->map.map_final[i - 1][j]))
		return (FALSE);
	if (j > 0 && !ft_strchr(ALLOWD_BRD, cub->map.map_final[i][j - 1]))
		return (FALSE);
	if (i < (cub->parsing.len_y - 1) && !ft_strchr(ALLOWD_BRD,
			cub->map.map_final[i + 1][j]))
		return (FALSE);
	if (j < (cub->parsing.len_x - 1) && !ft_strchr(ALLOWD_BRD,
			cub->map.map_final[i][j + 1]))
		return (FALSE);
	return (TRUE);
}

bool	check_borders(t_cub *cub, int len_x, int len_y, int i)
{
	int	j;

	j = -1;
	cub->parsing.len_x = len_x;
	cub->parsing.len_y = len_y;
	if (!check_x_borders(cub->map.map_final, len_y)
		|| !check_y_borders(cub->map.map_final, len_x, len_y))
		return (ft_exit(cub, "Map not surrended by walls"), false);
	while (cub->map.map_final[++i])
	{
		while (cub->map.map_final[i][++j])
		{
			if (cub->map.map_final[i][j] == '0'
				|| cub->map.map_final[i][j] == 'N'
				|| cub->map.map_final[i][j] == 'S'
				|| cub->map.map_final[i][j] == 'E'
				|| cub->map.map_final[i][j] == 'W')
				if (!check_borders_bis(cub, i, j))
					return (ft_exit(cub, "Map not surrended by walls"), false);
		}
		j = 0;
	}
	return (TRUE);
}
