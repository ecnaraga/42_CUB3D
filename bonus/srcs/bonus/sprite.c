/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:40:26 by athiebau          #+#    #+#             */
/*   Updated: 2024/05/17 15:29:53 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

static bool	ft_init_sprite_bis(t_cub *cub, int i)
{
	cub->ray.img[i].ptr = mlx_xpm_file_to_image(cub->mlx,
			cub->ray.path[i], &cub->ray.img[i].width, &cub->ray.img[i].height);
	if (!cub->ray.img[i].ptr)
		return (FALSE);
	cub->ray.img[i].addr = mlx_get_data_addr(cub->ray.img[i].ptr,
			&cub->ray.img[i].bpp, &cub->ray.img[i].line_len,
			&cub->ray.img[i].endian);
	if (!cub->ray.img[i].addr)
		return (FALSE);
	return (TRUE);
}

bool	ft_init_sprite(t_cub *cub)
{
	int		i;
	char	*str;

	str = "./scat0.xpm";
	i = -1;
	while (++i < 10)
	{
		cub->ray.path[i] = mcgic(ft_strdup(str), 0, ADD);
		cub->ray.path[i][6] += i;
	}
	i = -1;
	while (++i < 10)
	{
		if (!ft_init_sprite_bis(cub, i))
			return (FALSE);
	}
	i = -1;
	while (++i < 10)
		mcgic(cub->ray.path[i], 0, FREE);
	cub->ray.c_sprite = &cub->ray.img[0];
	return (TRUE);
}

static void	ft_cpy_pixel_sprite(t_draw *draw, t_img *img_src, t_img *img_dst,
		int *i)
{
	short int	k;
	int			j;

	k = -1;
	j = ft_abs(((int)draw->ty << 8) + ((int)draw->tx << 2));
	if (!((unsigned char)img_src->addr[j] == 255
			&& (unsigned char)img_src->addr[j + 1] == 255
			&& (unsigned char)img_src->addr[j + 2] == 255))
	{
		while (++k < img_dst->bpp >> 3 && *i + k < img_dst->size - 1 && j
			+ k < img_src->size - 1)
			img_dst->addr[*i + k] = img_src->addr[j + k];
	}
	draw->ty += draw->ty_inc;
	*i += img_dst->line_len;
}

static void	ft_put_spritecol_to_img(t_cub *cub, t_img *img_src, int x, int k)
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
	if (cub->ray.sprite[k].sprite == 1)
		cub->draw.tx = (int)(cub->ray.sprite[k].x) % img_src->width;
	while (++y < line_height)
		ft_cpy_pixel_sprite(&cub->draw, cub->ray.c_sprite, &cub->img, &i);
}

void	ft_draw_sprite(t_cub *cub, int x, double hm)
{
	t_pt	pt;
	int		i;

	i = cub->ray.last_sprite;
	while (i >= 0 && !cub->ray.sprite[i].sprite)
		i--;
	while (i >= 0)
	{
		cub->ray.sprite[i].dist = cub->ray.sprite[i].dist
			* cos(ft_deg_to_rad(cub->p.pa - cub->ray.a));
		cub->draw.hp = ((hm * HEIGHT) / cub->ray.sprite[i].dist);
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
		ft_put_spritecol_to_img(cub, cub->ray.c_sprite, x, i);
		i--;
	}
}
