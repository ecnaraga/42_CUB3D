/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:19:58 by galambey          #+#    #+#             */
/*   Updated: 2024/05/10 16:48:51 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

static void	ft_init_var(t_cub *cub, t_minimap *m)
{
	m->y = -1;
	m->x = 0;
	m->size = 144;
	m->dx = (int)(cub->p.x_pos * 16) - (m->size >> 1);
	m->dy = (int)(cub->p.y_pos * 16) - (m->size >> 1);
}

static void	ft_draw_sight_dir(t_cub *cub)
{
	t_pt	pt;
	double	a;

	a = ft_deg_to_rad(cub->p.pa);
	pt.xo = 72;
	pt.yo = 72;
	pt.xe = (double)pt.xo + (double)sin(a) * 15;
	pt.ye = (double)pt.yo - (double)cos(a) * 15;
	ft_draw_line(cub, pt, cub->map.t.color[4].color);
}

void	ft_draw_player(t_cub *cub)
{
	int		i;
	int		x;
	int		y;
	t_pt	pt;

	i = 0;
	x = 70;
	y = 70;
	ft_draw_sight_dir(cub);
	while (i < 5)
	{
		ft_set_pt(&pt, x, y, y + 5);
		ft_draw_vertical_line(pt, 0xFFFF00, cub);
		i++;
		x++;
	}
}

int	ft_draw_col_map(t_cub *cub, double co, t_minimap *m)
{
	t_pt	pt;

	m->xe = (m->x + 1) * co - m->dx;
	if (m->xe > m->size)
		return (1);
	m->ye = (m->y + 1) * co - m->dy;
	if (m->ye > m->size)
		m->ye = m->size;
	if (cub->map.map_final[m->y][m->x] == '1')
	{
		while (m->xo < m->xe)
		{
			ft_set_pt(&pt, m->xo++, m->yo, m->ye);
			ft_draw_vertical_line(pt, cub->map.t.color[2].color, cub);
		}
	}
	else
	{
		while (m->xo < m->xe)
		{
			ft_set_pt(&pt, m->xo++, m->yo, m->ye);
			ft_draw_vertical_line(pt, cub->map.t.color[3].color, cub);
		}
	}
	return (0);
}

void	ft_draw_map(t_cub *cub, double co)
{
	t_minimap	m;

	ft_init_var(cub, &m);
	while (cub->map.map_final[++m.y])
	{
		m.x = -1;
		while (cub->map.map_final[m.y][++m.x])
		{
			m.xo = m.x * co - m.dx;
			m.yo = m.y * co - m.dy;
			if (m.yo > m.size || m.xo > m.size)
				break ;
			if (cub->map.map_final[m.y][m.x] == '1'
				|| cub->map.map_final[m.y][m.x] == '2')
			{
				if (ft_draw_col_map(cub, co, &m))
					break ;
			}
		}
	}
	ft_draw_player(cub);
}
