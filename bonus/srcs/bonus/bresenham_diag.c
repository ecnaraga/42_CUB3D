/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_diag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:05:09 by garance           #+#    #+#             */
/*   Updated: 2024/05/10 02:26:20 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_draw_diag_h(t_cub *cub, t_pt pt, int color, t_var var)
{
	int	x;
	int	y;

	x = pt.xo;
	y = pt.yo;
	var.delta = 2 * var.dy;
	var.error = -var.dx;
	var.error_inc = -2 * var.dx;
	while (x != pt.xe + var.x_inc)
	{
		if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
			ft_img_pix_put(&cub->img, x, y, color);
		var.error += var.delta;
		if (var.error >= 0)
		{
			y += var.y_inc;
			var.error += var.error_inc;
		}
		x += var.x_inc;
	}
}

static void	ft_draw_diag_v(t_cub *cub, t_pt pt, int color, t_var var)
{
	int	x;
	int	y;

	x = pt.xo;
	y = pt.yo;
	var.delta = 2 * var.dx;
	var.error = -var.dy;
	var.error_inc = -2 * var.dy;
	while (y != pt.ye + var.y_inc)
	{
		if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
			ft_img_pix_put(&cub->img, x, y, color);
		var.error += var.delta;
		if (var.error >= 0)
		{
			x += var.x_inc;
			var.error += var.error_inc;
		}
		y += var.y_inc;
	}
}

void	ft_draw_line(t_cub *cub, t_pt pt, int color)
{
	t_var	var;

	var.dx = pt.xe - pt.xo;
	var.dy = pt.ye - pt.yo;
	var.x_inc = ft_sign(var.dx);
	var.y_inc = ft_sign(var.dy);
	var.dx = ft_abs(var.dx);
	var.dy = ft_abs(var.dy);
	if (var.dx >= var.dy)
		ft_draw_diag_h(cub, pt, color, var);
	else
		ft_draw_diag_v(cub, pt, color, var);
}
