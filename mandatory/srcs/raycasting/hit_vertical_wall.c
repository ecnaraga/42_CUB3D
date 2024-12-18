/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_vertical_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:32:11 by galambey          #+#    #+#             */
/*   Updated: 2024/05/14 10:16:26 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
Bit shifting avec >> 6 ou << 6 car hauteur du mur = 64 et 2^6 = 64
*/
static bool	ft_check_wall(t_cub *cub, double xo, double yo)
{
	int	mx;
	int	my;

	mx = (int)(cub->ray.xev) >> 6;
	my = (int)(cub->ray.yev) >> 6;
	if (ft_hit_wall(cub, mx, my))
		return (TRUE);
	cub->ray.xev += xo;
	cub->ray.yev += yo;
	return (FALSE);
}

static void	ft_init_value(t_cub *cub, double co, double *xo, double *yo)
{
	cub->ray.xev = (((int)cub->ray.xes >> 6) << 6) + co;
	cub->ray.yev = cub->ray.yes + (cub->ray.xes - cub->ray.xev)
		* cub->ray.tan_a;
	if (co < 0)
		*xo = -64.0;
	else
		*xo = 64.0;
	*yo = -*xo * cub->ray.tan_a;
}

/*
sin(a) > 0.001 => looking west
sin(a) < 0.001 => looking east
*/
void	ft_calcul_ray_vwall(t_cub *cub, double a)
{
	double	xo;
	double	yo;
	int		i;

	cub->ray.tan_a = 1 / tan(a);
	if (sin(a) < 0.001)
		ft_init_value(cub, -0.001, &xo, &yo);
	else if (sin(a) > 0.001)
		ft_init_value(cub, 64, &xo, &yo);
	else
		return (cub->ray.dist_wv = -1, (void)0);
	i = -1;
	while (++i < cub->map.map_height)
		if (ft_check_wall(cub, xo, yo))
			break ;
	cub->ray.dist_wv = sin(a) * (cub->ray.xev - cub->ray.xes) - cos(a)
		* (cub->ray.yev - cub->ray.yes);
	if (cub->ray.dist_wv < 0.000)
		cub->ray.dist_wv *= -1;
}
