/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:34:16 by athiebau          #+#    #+#             */
/*   Updated: 2024/05/10 16:36:28 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

void	ft_draw_img(t_cub *cub)
{
	double	hm;

	hm = 64.000;
	ft_pick_frames(cub);
	ft_draw_sight(cub, hm);
	ft_draw_map(cub, hm / 4);
}
