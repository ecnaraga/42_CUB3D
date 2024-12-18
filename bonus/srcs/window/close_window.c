/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:41:14 by athiebau          #+#    #+#             */
/*   Updated: 2024/05/17 02:49:54 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_exit_walls(t_cub *cub)
{
	if (cub->map.t.n_wall.ptr)
		mlx_destroy_image(cub->mlx, cub->map.t.n_wall.ptr);
	if (cub->map.t.s_wall.ptr)
		mlx_destroy_image(cub->mlx, cub->map.t.s_wall.ptr);
	if (cub->map.t.w_wall.ptr)
		mlx_destroy_image(cub->mlx, cub->map.t.w_wall.ptr);
	if (cub->map.t.e_wall.ptr)
		mlx_destroy_image(cub->mlx, cub->map.t.e_wall.ptr);
	if (cub->map.t.door.ptr)
		mlx_destroy_image(cub->mlx, cub->map.t.door.ptr);
}

void	ft_exit(t_cub *cub, char *err)
{
	int	i;

	i = 0;
	if (cub)
	{
		if (cub->ray.img[i].ptr)
			while (i < 10)
				mlx_destroy_image(cub->mlx, (cub->ray.img[i++].ptr));
		ft_exit_walls(cub);
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
	if (err)
		ft_printf("Error\n%s\n", err);
	mcgic(NULL, 0, FLUSH);
	exit(0);
}

int	ft_handle_cross(t_cub *cub)
{
	return (ft_exit(cub, NULL), 0);
}
