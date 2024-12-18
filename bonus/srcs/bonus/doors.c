/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:08:32 by galambey          #+#    #+#             */
/*   Updated: 2024/05/10 16:49:14 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

void	ft_open_doors(t_cub *cub)
{
	if (cub->map.map_final[(int)(cub->p.y_pos - cub->p.cos_mv
			* cub->door)][(int)(cub->p.x_pos + cub->p.sin_mv
			* cub->door)] == '2')
	{
		cub->map.t.color[3].color = 0x00FF00;
		cub->map.map_final[(int)(cub->p.y_pos - cub->p.cos_mv
				* cub->door)][(int)(cub->p.x_pos + cub->p.sin_mv
				* cub->door)] = '4';
	}
}

void	ft_close_doors(t_cub *cub)
{
	if (cub->map.map_final[(int)(cub->p.y_pos - cub->p.cos_mv
			* cub->door)][(int)(cub->p.x_pos + cub->p.sin_mv
			* cub->door)] == '4'
		&& cub->map.map_final[(int)(cub->p.y_pos)][(int)(cub->p.x_pos)] != '4')
		cub->map.map_final[(int)(cub->p.y_pos - cub->p.cos_mv
				* cub->door)][(int)(cub->p.x_pos + cub->p.sin_mv
				* cub->door)] = '2';
}
