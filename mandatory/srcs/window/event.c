/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:19:31 by galambey          #+#    #+#             */
/*   Updated: 2024/05/14 11:14:55 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_init_var(t_cub *cub, int *sign_cos, int *sign_sin)
{
	if (cub->p.sin_mv < 0.000)
		*sign_sin = -1;
	else
		*sign_sin = 1;
	if (cub->p.cos_mv < 0.000)
		*sign_cos = -1;
	else
		*sign_cos = 1;
}

static void	ft_send_to_window(t_cub *cub)
{
	t_img	tmp;

	tmp.ptr = cub->img.ptr;
	cub->img.ptr = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->img.ptr)
		ft_exit(cub, "Minilibx Error");
	cub->img.addr = mlx_get_data_addr(cub->img.ptr, &cub->img.bpp,
			&cub->img.line_len, &cub->img.endian);
	ft_draw_img(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.ptr, 0, 0);
	mlx_destroy_image(cub->mlx, tmp.ptr);
}

int	ft_handle_no_event(t_cub *cub)
{
	int	sign_cos;
	int	sign_sin;

	ft_init_var(cub, &sign_cos, &sign_sin);
	if (cub->key.w)
		ft_move_front(cub);
	if (cub->key.a)
		ft_move_left(cub);
	if (cub->key.s)
		ft_move_behind(cub);
	if (cub->key.d)
		ft_move_right(cub);
	if (cub->key.r)
		ft_rotate_right(cub);
	if (cub->key.l)
		ft_rotate_left(cub);
	ft_send_to_window(cub);
	return (0);
}

int	ft_handle_keys_press(int keycode, t_cub *cub)
{
	if (keycode == XK_Escape)
		ft_exit(cub, NULL);
	if (keycode == XK_w || keycode == XK_W)
		cub->key.w = TRUE;
	if (keycode == XK_a || keycode == XK_A)
		cub->key.a = TRUE;
	if (keycode == XK_s || keycode == XK_S)
		cub->key.s = TRUE;
	if (keycode == XK_d || keycode == XK_D)
		cub->key.d = TRUE;
	if (keycode == XK_Right)
		cub->key.r = TRUE;
	if (keycode == XK_Left)
		cub->key.l = TRUE;
	return (0);
}

int	ft_handle_keys_release(int keycode, t_cub *cub)
{
	if (keycode == XK_w || keycode == XK_W)
		cub->key.w = FALSE;
	if (keycode == XK_a || keycode == XK_A)
		cub->key.a = FALSE;
	if (keycode == XK_s || keycode == XK_S)
		cub->key.s = FALSE;
	if (keycode == XK_d || keycode == XK_D)
		cub->key.d = FALSE;
	if (keycode == XK_Right)
		cub->key.r = FALSE;
	if (keycode == XK_Left)
		cub->key.l = FALSE;
	return (0);
}
