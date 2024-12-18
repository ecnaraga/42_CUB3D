/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:42:35 by galambey          #+#    #+#             */
/*   Updated: 2024/05/17 15:45:15 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_adapt_speed(t_cub *cub, char **env)
{
	int	i;

	i = 0;
	cub->speed = 0.02;
	cub->inc_a = 1;
	cub->door = 50;
	while (env && env[i])
	{
		if (!ft_strcmp(env[i++], "_=/usr/bin/valgrind"))
		{
			cub->speed = 0.2;
			cub->inc_a = 5;
			cub->door = 5;
		}
	}
}

static void	ft_init_var(t_cub *cub, char **env)
{
	int	i;

	i = -1;
	cub->mlx = NULL;
	cub->mlx_win = NULL;
	cub->img.ptr = NULL;
	cub->map.t.n_wall.ptr = NULL;
	cub->map.t.s_wall.ptr = NULL;
	cub->map.t.w_wall.ptr = NULL;
	cub->map.t.e_wall.ptr = NULL;
	cub->map.t.door.ptr = NULL;
	cub->key.a = FALSE;
	cub->key.w = FALSE;
	cub->key.d = FALSE;
	cub->key.s = FALSE;
	cub->key.r = FALSE;
	cub->key.l = FALSE;
	cub->key.click = FALSE;
	cub->key.open = FALSE;
	cub->key.close = FALSE;
	cub->ray.nb_sprite = 0;
	cub->ray.count = 0;
	while (++i < 10)
		cub->ray.img[i].ptr = NULL;
	ft_adapt_speed(cub, env);
}

static void	ft_init_sprite(t_cub *cub)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = -1;
	cub->ray.sprite = mcgic(NULL, (cub->ray.nb_sprite * sizeof(t_sprite)), MLC);
	if (!cub->ray.sprite)
		ft_exit(cub, "Allocation failed");
	while (cub->map.map_final[++i])
	{
		j = 0;
		while (cub->map.map_final[i][j])
		{
			if (cub->map.map_final[i][j] == '3')
			{
				cub->ray.sprite[++k].x = j;
				cub->ray.sprite[k].y = i;
			}
			j++;
		}
	}
}

int	main(int ac, char **av, char **env)
{
	t_cub	cub;

	if (ac == 2)
	{
		ft_init_var(&cub, env);
		ft_get_textures(&cub, av[1]);
		ft_init_sprite(&cub);
		ft_open_window(&cub);
	}
}
