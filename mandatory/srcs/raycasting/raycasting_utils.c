/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:56:22 by galambey          #+#    #+#             */
/*   Updated: 2024/05/17 12:06:04 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	ft_hit_wall(t_cub *cub, int x, int y)
{
	if (x < 0 || y < 0)
		return (TRUE);
	if (y > cub->map.map_height - 1 || x > cub->map.map_width - 1)
		return (TRUE);
	if (cub->map.map_final[y][x] == '1')
	{
		return (TRUE);
	}
	return (FALSE);
}

// AVEC COLOR VOIR CE QU ON FAIT
void	ft_set_ray(t_ray *ray)
{
	int	color_w;

	(void)color_w;
	if (ray->hit == 0)
	{
		ray->xe = ray->xeh;
		ray->ye = ray->yeh;
		ray->dist_w = ray->dist_wh;
		ray->hit = 0;
		color_w = 0x00FF00;
	}
	else
	{
		ray->xe = ray->xev;
		ray->ye = ray->yev;
		ray->dist_w = ray->dist_wv;
		ray->hit = 1;
		color_w = 0x0000FF;
	}
}

void	ft_set_dist(t_ray *ray)
{
	if (ray->dist_wv == -1 || (ray->dist_wh > -1
			&& ray->dist_wh < ray->dist_wv))
		ray->hit = 0;
	else
		ray->hit = 1;
	ft_set_ray(ray);
}

void	ft_cpy_ray(t_ray ray_src, t_ray *ray_dst)
{
	ray_dst->dist_wh = ray_src.dist_wh;
	ray_dst->dist_wv = ray_src.dist_wv;
	ray_dst->hit = ray_src.hit;
	ray_dst->xeh = ray_src.xeh;
	ray_dst->yeh = ray_src.yeh;
	ray_dst->yev = ray_src.yev;
	ray_dst->xev = ray_src.xev;
	ray_dst->a = ray_src.a;
}
