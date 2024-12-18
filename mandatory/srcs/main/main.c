/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:42:35 by galambey          #+#    #+#             */
/*   Updated: 2024/05/08 15:11:39 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_adapt_speed(t_cub *cub, char **env)
{
	int	i;

	i = 0;
	cub->speed = 0.02;
	cub->inc_a = 1;
	while (env && env[i])
	{
		if (!ft_strcmp(env[i++], "_=/usr/bin/valgrind"))
		{
			cub->speed = 0.2;
			cub->inc_a = 5;
		}
	}
}

static void	ft_init_var(t_cub *cub, char **env)
{
	cub->mlx = NULL;
	cub->mlx_win = NULL;
	cub->img.ptr = NULL;
	cub->map.t.n_wall.ptr = NULL;
	cub->map.t.s_wall.ptr = NULL;
	cub->map.t.w_wall.ptr = NULL;
	cub->map.t.e_wall.ptr = NULL;
	cub->key.a = FALSE;
	cub->key.w = FALSE;
	cub->key.d = FALSE;
	cub->key.s = FALSE;
	cub->key.r = FALSE;
	cub->key.l = FALSE;
	ft_adapt_speed(cub, env);
}

int	main(int ac, char **av, char **env)
{
	t_cub	cub;

	if (ac == 2)
	{
		ft_init_var(&cub, env);
		ft_get_textures(&cub, av[1]);
		ft_open_window(&cub);
	}
}
