/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:21:22 by galambey          #+#    #+#             */
/*   Updated: 2024/05/17 15:31:20 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "cub3d.h"

/* ******************************* MINI_MAP ******************************** */

void	ft_draw_player(t_cub *cub);
void	ft_draw_map(t_cub *cub, double co);

/* ********************************* DOORS ********************************* */

void	ft_open_doors(t_cub *cub);
void	ft_close_doors(t_cub *cub);

/* ********************************* MOUSE ********************************* */

int		handle_mouse(int x, int y, t_cub *cub);
int		mouse_click(int button, t_cub *cub);

/* ******************************** SPRITE ********************************* */

bool	ft_init_sprite(t_cub *cub);
void	ft_pick_frames(t_cub *cub);
void	ft_draw_sprite(t_cub *cub, int x, double hm);
void	ft_set_sprite(t_ray *ray, double a);

#endif