/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:39:42 by athiebau          #+#    #+#             */
/*   Updated: 2024/05/10 17:39:44 by athiebau         ###   ########.fr       */
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
	if (!ft_strcmp(type, "DO"))
		return (DO);
	if (!ft_strcmp(type, "F"))
		return (F);
	if (!ft_strcmp(type, "C"))
		return (C);
	if (!ft_strcmp(type, "M"))
		return (M);
	if (!ft_strcmp(type, "P"))
		return (D);
	if (!ft_strcmp(type, "R"))
		return (R);
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
			if (line[*j] == 'F' || line[*j] == 'C' || line[*j] == 'M'
				|| line[*j] == 'P' || line[*j] == 'R' || ++i == 2)
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
