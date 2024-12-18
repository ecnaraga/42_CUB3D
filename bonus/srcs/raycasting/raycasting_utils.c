/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:56:22 by galambey          #+#    #+#             */
/*   Updated: 2024/05/17 15:26:01 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_find_sprite(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->ray.nb_sprite > 0 && !cub->ray.hv)
	{
		while (cub->ray.sprite[i].sprite == 1)
			i++;
		if (cub->ray.sprite[i].sprite == 0)
		{
			cub->ray.sprite[i].sprite = 1;
			cub->ray.sprite[i].x = cub->ray.xeh;
			cub->ray.sprite[i].y = cub->ray.yeh;
		}
	}
	return (i);
}

bool	ft_hit_wall(t_cub *cub, int x, int y, int *door)
{
	if (x < 0 || y < 0)
		return (TRUE);
	if (y > cub->map.map_height - 1 || x > cub->map.map_width - 1)
		return (TRUE);
	if (cub->map.map_final[y][x] == '1')
		return (TRUE);
	if (cub->map.map_final[y][x] == '2')
		return (*door = 1, TRUE);
	if (cub->map.map_final[y][x] == '3')
	{
		cub->ray.last_sprite = ft_find_sprite(cub);
		return (FALSE);
	}
	return (FALSE);
}

void	ft_set_ray(t_ray *ray)
{
	if (ray->hit == 0)
	{
		ray->dist_w = ray->dist_wh;
		ray->hit = 0;
	}
	else
	{
		ray->dist_w = ray->dist_wv;
		ray->hit = 1;
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
	ray_dst->doorh = ray_src.doorh;
	ray_dst->doorv = ray_src.doorv;
}
