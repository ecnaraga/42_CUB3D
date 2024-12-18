/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:28:01 by athiebau          #+#    #+#             */
/*   Updated: 2024/05/14 10:14:16 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	handle_mouse(int x, int y, t_cub *cub)
{
	static int	last_x;

	last_x = WIDTH / 2;
	(void)y;
	if (last_x == x || cub->key.click == FALSE)
		return (0);
	if (x < (WIDTH / 2))
	{
		cub->p.pa -= 1;
		if (cub->p.pa <= 0.001)
			cub->p.pa = 360;
		cub->p.sin_mv = sin(ft_deg_to_rad(cub->p.pa)) * cub->speed;
		cub->p.cos_mv = cos(ft_deg_to_rad(cub->p.pa)) * cub->speed;
	}
	else if (x > (WIDTH / 2))
	{
		cub->p.pa += 1;
		if (cub->p.pa >= 359.009)
			cub->p.pa = 1;
		cub->p.sin_mv = sin(ft_deg_to_rad(cub->p.pa)) * cub->speed;
		cub->p.cos_mv = cos(ft_deg_to_rad(cub->p.pa)) * cub->speed;
	}
	last_x = x;
	mlx_mouse_move(cub->mlx, cub->mlx_win, WIDTH / 2, HEIGHT / 2);
	return (0);
}

int	mouse_click(int button, int x, int y, t_cub *cub)
{
	(void)x;
	(void)y;
	if (button == 1 && cub->key.click == FALSE)
		cub->key.click = TRUE;
	else if (button == 1)
		cub->key.click = FALSE;
	return (0);
}
