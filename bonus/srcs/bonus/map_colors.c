/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:39:50 by athiebau          #+#    #+#             */
/*   Updated: 2024/05/10 17:39:52 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_fill_color(char *s, int *color, int *err)
{
	int	i;

	i = 0;
	while (s[i] && ft_isspace_nonewline(s[i]))
		i++;
	if (!s[i] || s[i] == '\n')
		return (*err = 1, (void)0);
	while (s[i] && ft_isdigit(s[i]))
		i++;
	while (s[i] && ft_isspace_nonewline(s[i]))
		i++;
	if (s[i] && s[i] != '\n')
		return (*err = 1, (void)0);
	*color = ft_atoi_handle_overflow(s, err);
	if (*color < 0 || *color > 255)
		*err = 1;
}

static void	ft_cpy_color(t_cub *cub, char *line, t_color *color)
{
	char	**tmp;
	int		err;

	if (color->empty != 0)
		ft_exit(cub, "Type identifyer already filled");
	tmp = ft_split_mcgic(line, ',');
	if (!tmp)
		ft_exit(cub, "Dynamic allocation failed");
	if (ft_arraylen(tmp) != 3)
		ft_exit(cub, "Wrong RGB colors");
	err = 0;
	ft_fill_color(tmp[0], &color->r, &err);
	ft_fill_color(tmp[1], &color->g, &err);
	ft_fill_color(tmp[2], &color->b, &err);
	if (err == 1)
		ft_exit(cub, "Wrong RGB colors");
	color->color = color->r;
	color->color = (color->color << 8) + color->g;
	color->color = (color->color << 8) + color->b;
	color->empty = 1;
}

void	ft_handle_colors(t_cub *cub, char *line, int id)
{
	if (id == F)
		ft_cpy_color(cub, line, &cub->map.t.color[0]);
	else if (id == C)
		ft_cpy_color(cub, line, &cub->map.t.color[1]);
	else if (id == M)
		ft_cpy_color(cub, line, &cub->map.t.color[2]);
	else if (id == D)
		ft_cpy_color(cub, line, &cub->map.t.color[3]);
	else
		ft_cpy_color(cub, line, &cub->map.t.color[4]);
}
