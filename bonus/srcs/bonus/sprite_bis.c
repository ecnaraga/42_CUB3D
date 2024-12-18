/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:31:04 by athiebau          #+#    #+#             */
/*   Updated: 2024/05/17 15:31:14 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

void	ft_set_sprite(t_ray *ray, double a)
{
	int	i;

	i = 0;
	if (ray->nb_sprite > 0)
	{
		while (i <= ray->last_sprite && ray->sprite[i].sprite)
		{
			ray->sprite[i].dist = sin(a) * (ray->sprite[i].x - ray->xes)
				- cos(a) * (ray->sprite[i].y - ray->yes);
			if (ray->sprite[i].dist > ray->dist_w)
				ray->sprite[i].sprite = 0;
			i++;
		}
	}
}

static void	ft_pick_frames_bis(t_cub *cub, int i)
{
	if (cub->ray.count == i * 14)
		cub->ray.c_sprite = &cub->ray.img[7];
	else if (cub->ray.count == i * 16)
		cub->ray.c_sprite = &cub->ray.img[8];
	else if (cub->ray.count == i * 18)
		cub->ray.c_sprite = &cub->ray.img[9];
	else if (cub->ray.count == i * 20)
	{
		cub->ray.c_sprite = &cub->ray.img[0];
		cub->ray.count = 0;
	}
}

void	ft_pick_frames(t_cub *cub)
{
	int	i;

	i = 8;
	if (cub->ray.count == i * 2)
		cub->ray.c_sprite = &cub->ray.img[1];
	else if (cub->ray.count == i * 4)
		cub->ray.c_sprite = &cub->ray.img[2];
	else if (cub->ray.count == i * 6)
		cub->ray.c_sprite = &cub->ray.img[3];
	else if (cub->ray.count == i * 8)
		cub->ray.c_sprite = &cub->ray.img[4];
	else if (cub->ray.count == i * 10)
		cub->ray.c_sprite = &cub->ray.img[5];
	else if (cub->ray.count == i * 12)
		cub->ray.c_sprite = &cub->ray.img[6];
	else
		ft_pick_frames_bis(cub, i);
	cub->ray.count++;
}
