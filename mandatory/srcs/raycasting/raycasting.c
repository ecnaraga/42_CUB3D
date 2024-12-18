/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:55:16 by galambey          #+#    #+#             */
/*   Updated: 2024/05/03 11:41:34 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw(t_cub *cub, t_ray ray, int x, double hm)
{
	t_pt	pt;

	ray.dist_w = ray.dist_w * cos(ft_deg_to_rad(cub->p.pa - ray.a));
	cub->draw.hp = ((hm * HEIGHT) / ray.dist_w);
	cub->draw.ty_inc = 64.0 / (double)cub->draw.hp;
	cub->draw.ty_off = 0;
	if (cub->draw.hp > HEIGHT)
	{
		cub->draw.ty_off = (cub->draw.hp - HEIGHT) / 2.0;
		cub->draw.hp = HEIGHT;
	}
	cub->draw.hr = cub->draw.hp / 2.0;
	cub->draw.start = (int)round(((int)HEIGHT >> 1) - cub->draw.hr);
	cub->draw.end = (int)round(((int)HEIGHT >> 1) + cub->draw.hr);
	ft_set_pt(&pt, x, 0, cub->draw.start);
	ft_draw_vertical_line(pt, cub->map.t.color[1].color, cub);
	ft_put_textcol_to_img(cub, ray, x);
	ft_set_pt(&pt, x, cub->draw.end, HEIGHT);
	ft_draw_vertical_line(pt, cub->map.t.color[0].color, cub);
}

static void	ft_init_var(t_cub *cub, double hm)
{
	cub->ray.xes = cub->p.x_pos * hm;
	cub->ray.yes = cub->p.y_pos * hm;
	cub->ray.a = cub->p.pa - 30;
}

void	ft_draw_sight(t_cub *cub, double hm)
{
	t_ray	m1;
	t_ray	m2;
	double	a_inc;
	int		x;

	ft_init_var(cub, hm);
	a_inc = 60.0 / (double)WIDTH;
	x = -1;
	while (++x < WIDTH)
	{
		ft_calcul_ray_hwall(cub, ft_deg_to_rad(cub->ray.a));
		ft_calcul_ray_vwall(cub, ft_deg_to_rad(cub->ray.a));
		ft_set_dist(&cub->ray);
		ft_draw(cub, cub->ray, x, hm);
		if (x > 1 && m2.hit == cub->ray.hit && m2.hit != m1.hit)
		{
			m1.hit = m2.hit;
			ft_set_ray(&m1);
			ft_draw(cub, m1, x - 1, hm);
		}
		if (x > 0)
			ft_cpy_ray(m1, &m2);
		ft_cpy_ray(cub->ray, &m1);
		cub->ray.a += a_inc;
	}
}

void	ft_draw_img(t_cub *cub)
{
	double	hm;

	hm = 64.000;
	ft_draw_sight(cub, hm);
}
