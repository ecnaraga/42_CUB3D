/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:47:29 by galambey          #+#    #+#             */
/*   Updated: 2024/05/17 15:28:27 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp >> 3));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	ft_cpy_pixel(t_draw *draw, t_img *img_src, t_img *img_dst, int *i)
{
	short int	k;
	int			j;

	k = -1;
	j = ft_abs(((int)draw->ty << 8) + ((int)draw->tx << 2));
	while (++k < img_dst->bpp >> 3 && *i + k < img_dst->size - 1 && j
		+ k < img_src->size - 1)
		img_dst->addr[*i + k] = img_src->addr[j + k];
	draw->ty += draw->ty_inc;
	*i += img_dst->line_len;
}

static void	ft_put_coltoimg(t_cub *cub, t_ray ray, t_img *img_src, int x)
{
	int	y;
	int	i;
	int	line_height;

	y = -1;
	i = cub->draw.start * cub->img.line_len + (x << 2);
	line_height = (cub->draw.end - cub->draw.start + 1);
	cub->draw.ty = cub->draw.ty_inc * cub->draw.ty_off;
	cub->img.size = HEIGHT * cub->img.line_len;
	img_src->size = img_src->height * img_src->line_len;
	if (ray.hit == 0)
		cub->draw.tx = (int)(ray.xeh) % img_src->width;
	else
		cub->draw.tx = (int)(ray.yev) % img_src->width;
	while (++y < line_height)
		ft_cpy_pixel(&cub->draw, img_src, &cub->img, &i);
}

void	ft_put_textcol_to_img(t_cub *cub, t_ray ray, int x)
{
	if (!cub->ray.hit)
	{
		if (ray.doorh)
			ft_put_coltoimg(cub, ray, &cub->map.t.door, x);
		else if (cos(ft_deg_to_rad(ray.a)) >= 0.000)
			ft_put_coltoimg(cub, ray, &cub->map.t.n_wall, x);
		else
			ft_put_coltoimg(cub, ray, &cub->map.t.s_wall, x);
	}
	if (cub->ray.hit)
	{
		if (ray.doorv)
			ft_put_coltoimg(cub, ray, &cub->map.t.door, x);
		else if (sin(ft_deg_to_rad(ray.a)) >= 0.000)
			ft_put_coltoimg(cub, ray, &cub->map.t.e_wall, x);
		else
			ft_put_coltoimg(cub, ray, &cub->map.t.w_wall, x);
	}
}
