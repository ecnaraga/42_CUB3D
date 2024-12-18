/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:06:37 by galambey          #+#    #+#             */
/*   Updated: 2024/05/13 18:52:23 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_rotate_right(t_cub *cub)
{
	cub->p.pa += cub->inc_a;
	if (cub->p.pa >= 359.009)
		cub->p.pa = cub->inc_a;
	cub->p.sin_mv = sin(ft_deg_to_rad(cub->p.pa)) * cub->speed;
	cub->p.cos_mv = cos(ft_deg_to_rad(cub->p.pa)) * cub->speed;
}

void	ft_rotate_left(t_cub *cub)
{
	cub->p.pa -= cub->inc_a;
	if (cub->p.pa <= 0.001)
		cub->p.pa = 360;
	cub->p.sin_mv = sin(ft_deg_to_rad(cub->p.pa)) * cub->speed;
	cub->p.cos_mv = cos(ft_deg_to_rad(cub->p.pa)) * cub->speed;
}
