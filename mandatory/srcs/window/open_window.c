/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:35:49 by galambey          #+#    #+#             */
/*   Updated: 2024/05/15 17:13:44 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <X11/keysym.h>

static void	ft_get_addr_xpm_texture(t_cub *cub)
{
	cub->map.t.n_wall.addr = mlx_get_data_addr(cub->map.t.n_wall.ptr,
			&cub->map.t.n_wall.bpp, &cub->map.t.n_wall.line_len,
			&cub->map.t.n_wall.endian);
	cub->map.t.s_wall.addr = mlx_get_data_addr(cub->map.t.s_wall.ptr,
			&cub->map.t.s_wall.bpp, &cub->map.t.s_wall.line_len,
			&cub->map.t.s_wall.endian);
	cub->map.t.w_wall.addr = mlx_get_data_addr(cub->map.t.w_wall.ptr,
			&cub->map.t.w_wall.bpp, &cub->map.t.w_wall.line_len,
			&cub->map.t.w_wall.endian);
	cub->map.t.e_wall.addr = mlx_get_data_addr(cub->map.t.e_wall.ptr,
			&cub->map.t.e_wall.bpp, &cub->map.t.e_wall.line_len,
			&cub->map.t.e_wall.endian);
	if (!cub->map.t.n_wall.addr || !cub->map.t.s_wall.addr
		|| !cub->map.t.w_wall.addr || !cub->map.t.e_wall.addr)
		ft_exit(cub, "Wrong Texture");
}

static void	ft_open_xpm_texture(t_cub *cub)
{
	cub->map.t.n_wall.ptr = mlx_xpm_file_to_image(cub->mlx, cub->map.t.tex[NO],
			&cub->map.t.n_wall.width, &cub->map.t.n_wall.height);
	cub->map.t.s_wall.ptr = mlx_xpm_file_to_image(cub->mlx, cub->map.t.tex[SO],
			&cub->map.t.s_wall.width, &cub->map.t.s_wall.height);
	cub->map.t.w_wall.ptr = mlx_xpm_file_to_image(cub->mlx, cub->map.t.tex[WE],
			&cub->map.t.w_wall.width, &cub->map.t.w_wall.height);
	cub->map.t.e_wall.ptr = mlx_xpm_file_to_image(cub->mlx, cub->map.t.tex[EA],
			&cub->map.t.e_wall.width, &cub->map.t.e_wall.height);
	if (!cub->map.t.n_wall.ptr || !cub->map.t.s_wall.ptr
		|| !cub->map.t.w_wall.ptr || !cub->map.t.e_wall.ptr)
		ft_exit(cub, "Wrong Texture");
	ft_get_addr_xpm_texture(cub);
}

void	ft_open_window(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		ft_exit(cub, "Minilibx Error");
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3D");
	if (!cub->mlx_win)
		ft_exit(cub, "Minilibx Error");
	cub->img.ptr = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->img.ptr)
		ft_exit(cub, "Minilibx Error");
	cub->img.addr = mlx_get_data_addr(cub->img.ptr, &cub->img.bpp,
			&cub->img.line_len, &cub->img.endian);
	if (!cub->img.addr)
		ft_exit(cub, "Minilibx Error");
	ft_open_xpm_texture(cub);
	mlx_loop_hook(cub->mlx, ft_handle_no_event, cub);
	mlx_hook(cub->mlx_win, KeyPress, KeyPressMask, ft_handle_keys_press, cub);
	mlx_hook(cub->mlx_win, KeyRelease, KeyReleaseMask, ft_handle_keys_release,
		cub);
	mlx_hook(cub->mlx_win, DestroyNotify, StructureNotifyMask, ft_handle_cross,
		cub);
	mlx_loop(cub->mlx);
}
