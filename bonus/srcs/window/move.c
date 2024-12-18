/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:57:54 by galambey          #+#    #+#             */
/*   Updated: 2024/05/10 16:29:30 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	ft_stop(t_cub *cub, double y, double x)
{
	if (cub->map.map_final[(int)y][(int)x] == '1'
		|| cub->map.map_final[(int)y][(int)x] == '2')
		return (TRUE);
	return (FALSE);
}

void	ft_move_front(t_cub *cub)
{
	if (!ft_stop(cub, cub->p.y_pos - cub->p.cos_mv, cub->p.x_pos))
			cub->p.y_pos -= cub->p.cos_mv;
	if (!ft_stop(cub, cub->p.y_pos, cub->p.x_pos + cub->p.sin_mv))
			cub->p.x_pos += cub->p.sin_mv;
}

void	ft_move_behind(t_cub *cub)
{
	if (!ft_stop(cub, cub->p.y_pos + cub->p.cos_mv, cub->p.x_pos))
			cub->p.y_pos += cub->p.cos_mv;
	if (!ft_stop(cub, cub->p.y_pos, cub->p.x_pos - cub->p.sin_mv))
			cub->p.x_pos -= cub->p.sin_mv;
}

void	ft_move_right(t_cub *cub)
{
	if (!ft_stop(cub, cub->p.y_pos + cub->p.sin_mv, cub->p.x_pos))
			cub->p.y_pos += cub->p.sin_mv;
	if (!ft_stop(cub, cub->p.y_pos, cub->p.x_pos + cub->p.cos_mv))
			cub->p.x_pos += cub->p.cos_mv;
}

void	ft_move_left(t_cub *cub)
{
	if (!ft_stop(cub, cub->p.y_pos - cub->p.sin_mv, cub->p.x_pos))
			cub->p.y_pos -= cub->p.sin_mv;
	if (!ft_stop(cub, cub->p.y_pos, cub->p.x_pos - cub->p.cos_mv))
			cub->p.x_pos -= cub->p.cos_mv;
}
