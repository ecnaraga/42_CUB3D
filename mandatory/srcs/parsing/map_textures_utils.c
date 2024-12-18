/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:27:41 by galambey          #+#    #+#             */
/*   Updated: 2024/05/14 11:14:55 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static short int	ft_define_identifier(char type[])
{
	if (!ft_strcmp(type, "NO"))
		return (NO);
	if (!ft_strcmp(type, "SO"))
		return (SO);
	if (!ft_strcmp(type, "WE"))
		return (WE);
	if (!ft_strcmp(type, "EA"))
		return (EA);
	if (!ft_strcmp(type, "F"))
		return (F);
	if (!ft_strcmp(type, "C"))
		return (C);
	return (-1);
}

short int	ft_get_type_info(char *line, int *j)
{
	int		i;
	char	type[3];

	ft_bzero(type, 3);
	i = 0;
	*j = 0;
	while (line[*j] && ft_isspace_nonewline(line[*j]))
		(*j)++;
	while (line[*j] && i < 2)
	{
		if (ft_isspace_nonewline(line[*j]))
			return (-1);
		if (!ft_isspace_nonewline(line[*j]))
		{
			type[i] = line[*j];
			i++;
			if (line[*j] == 'F' || line[*j] == 'C' || i == 2)
				break ;
		}
		(*j)++;
	}
	if (!line[*j] || !line[*j + 1] || !ft_isspace_nonewline(line[*j + 1]))
		return (-1);
	(*j)++;
	return (ft_define_identifier(type));
}

int	ft_count_letter(char *line, int j)
{
	int	count;

	count = 0;
	while (line[j] && ft_isspace_nonewline(line[j]))
		j++;
	while (line[j])
	{
		if (ft_isspace_nonewline(line[j]) || line[j] == '\n')
			break ;
		count++;
		j++;
	}
	while (line[j])
	{
		if (!ft_isspace_nonewline(line[j]) && line[j] != '\n')
			return (-1);
		j++;
	}
	return (count);
}

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

void	ft_cpy_color(t_cub *cub, char *line, t_color *color)
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
