/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_horizontal_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:09:52 by galambey          #+#    #+#             */
/*   Updated: 2024/05/10 16:42:54 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
Bit shifting avec >> 6 ou << 6 car hauteur du mur = 64 et 2^6 = 64
*/
static bool	ft_check_wall(t_cub *cub, double xo, double yo, int *door)
{
	int	mx;
	int	my;

	mx = (int)(cub->ray.xeh) >> 6;
	my = (int)(cub->ray.yeh) >> 6;
	if (ft_hit_wall(cub, mx, my, door))
		return (TRUE);
	cub->ray.xeh += xo;
	cub->ray.yeh += yo;
	return (FALSE);
}

static void	ft_init_var(t_cub *cub, double co, double *xo, double *yo)
{
	cub->ray.hv = 0;
	cub->ray.yeh = (((int)cub->ray.yes >> 6) << 6) + co;
	cub->ray.xeh = cub->ray.xes + (cub->ray.yes - cub->ray.yeh)
		* cub->ray.tan_a;
	if (co < 0)
		*yo = -64.0;
	else
		*yo = 64.0;
	*xo = -*yo * cub->ray.tan_a;
}

/*
cos(a) > 0.001 => looking north
cos(a) < 0.001 => looking south
*/
void	ft_calcul_ray_hwall(t_cub *cub, double a)
{
	double	xo;
	double	yo;
	int		i;

	cub->ray.tan_a = tan(a);
	cub->ray.doorh = 0;
	if (cos(a) > 0.001)
		ft_init_var(cub, -0.001, &xo, &yo);
	else if (cos(a) < 0.001)
		ft_init_var(cub, 64, &xo, &yo);
	else
		return (cub->ray.dist_wh = -1, (void)0);
	i = -1;
	while (++i < cub->map.map_height)
		if (ft_check_wall(cub, xo, yo, &cub->ray.doorh))
			break ;
	cub->ray.dist_wh = sin(a) * (cub->ray.xeh - cub->ray.xes) - cos(a)
		* (cub->ray.yeh - cub->ray.yes);
	if (cub->ray.dist_wh < 0.000)
		cub->ray.dist_wh *= -1;
}
