/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:42:15 by galambey          #+#    #+#             */
/*   Updated: 2024/05/14 12:02:35 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_exit(t_cub *cub, char *err)
{
	if (cub)
	{
		if (cub->map.t.n_wall.ptr)
			mlx_destroy_image(cub->mlx, cub->map.t.n_wall.ptr);
		if (cub->map.t.s_wall.ptr)
			mlx_destroy_image(cub->mlx, cub->map.t.s_wall.ptr);
		if (cub->map.t.w_wall.ptr)
			mlx_destroy_image(cub->mlx, cub->map.t.w_wall.ptr);
		if (cub->map.t.e_wall.ptr)
			mlx_destroy_image(cub->mlx, cub->map.t.e_wall.ptr);
		if (cub->img.ptr)
			mlx_destroy_image(cub->mlx, cub->img.ptr);
		if (cub->mlx_win)
			mlx_destroy_window(cub->mlx, cub->mlx_win);
		if (cub->mlx)
		{
			mlx_destroy_display(cub->mlx);
			free(cub->mlx);
		}
	}
	mcgic(NULL, 0, FLUSH);
	if (err)
		(ft_printf("Error\n%s\n", err), exit(1));
	exit(0);
}

int	ft_handle_cross(t_cub *cub)
{
	return (ft_exit(cub, NULL), 0);
}
