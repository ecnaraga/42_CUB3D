/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_vh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:11:17 by galambey          #+#    #+#             */
/*   Updated: 2024/05/03 18:17:26 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_set_pt(t_pt *pt, int x, int yo, int ye)
{
	pt->xo = x;
	pt->yo = yo;
	pt->ye = ye;
}

void	ft_draw_vertical_line(t_pt pt, int color, t_cub *cub)
{
	int	inc;

	inc = ft_sign(pt.ye - pt.yo);
	while (pt.yo != pt.ye)
	{
		if (pt.yo >= 0 && pt.yo < HEIGHT && pt.xo >= 0 && pt.xo < WIDTH)
			ft_img_pix_put(&cub->img, pt.xo, pt.yo, color);
		pt.yo += inc;
	}
}
