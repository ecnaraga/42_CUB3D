/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:39:34 by athiebau          #+#    #+#             */
/*   Updated: 2024/05/15 17:56:49 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	ft_check_name(t_cub *cub, char *av)
{
	if (ft_rstrncmp(av, ".cub", 4))
		ft_exit(cub, "Wrong Extension");
	return (TRUE);
}

static void	ft_cpy_texture(t_cub *cub, char *line, char *texture, int j)
{
	int	i;

	i = 0;
	while (line[j])
	{
		if (ft_isspace_nonewline(line[j]) || line[j] == '\n')
			break ;
		texture[i] = line[j];
		j++;
		i++;
	}
	if (i == 0)
		ft_exit(cub, "No path to texture");
	texture[i] = '\0';
}

static void	ft_fill_textures(t_cub *cub, char *line)
{
	int			j;
	short int	id;
	int			count;

	id = ft_get_type_info(line, &j);
	if (id == -1)
		ft_exit(cub, "Wrong type identifyer");
	while (line[j] && ft_isspace_nonewline(line[j]))
		j++;
	if (id < F)
	{
		if (cub->map.t.tex[id])
			ft_exit(cub, "Type identifyer already filled");
		count = ft_count_letter(line, j);
		if (count == -1)
			ft_exit(cub, "Wrong path to texture");
		cub->map.t.tex[id] = mcgic(NULL, sizeof(char) * (count + 1), MLC);
		if (!cub->map.t.tex)
			ft_exit(cub, "Dynamic allocation failed");
		ft_cpy_texture(cub, line, cub->map.t.tex[id], j);
	}
	else
		ft_handle_colors(cub, line + j, id);
}

static void	ft_init_texture(t_cub *cub, char *av)
{
	int	i;

	if (ft_strlen(av) <= 4 || !ft_check_name(cub, av))
		ft_exit(cub, "Wrong Argument");
	cub->map.fd = open(av, O_RDONLY);
	if (cub->map.fd == -1)
		ft_exit(cub, "Argument doesn't exist");
	cub->map.t.tex = mcgic(NULL, sizeof(char *) * 6, MLC);
	if (!cub->map.t.tex)
		ft_exit(cub, "Dynamic allocation failed");
	i = 0;
	while (i < 6)
		cub->map.t.tex[i++] = NULL;
	cub->map.t.color[0].empty = 0;
	cub->map.t.color[1].empty = 0;
	cub->map.t.color[2].empty = 0;
	cub->map.t.color[3].empty = 0;
	cub->map.t.color[4].empty = 0;
}

void	ft_get_textures(t_cub *cub, char *av)
{
	char	*line;
	int		i;
	int		flag;

	flag = 0;
	ft_init_texture(cub, av);
	i = 0;
	while (i < 10)
	{
		line = get_next_line(cub->map.fd);
		if (line && !mcgic(line, 0, ADD))
			ft_exit(cub, "Dynamic allocation failed");
		if (((i == 0 || (i > 0 && flag == 0)) && !line))
			ft_exit(cub, "Empty file");
		if ((i > 0 && flag == 1 && !line))
			ft_exit(cub, "Wrong type identifyers");
		if (!line[0] || line[0] == '\n')
			continue ;
		flag = 1;
		ft_fill_textures(cub, line);
		mcgic(line, 0, FREE);
		i++;
	}
	if (!get_map(cub, cub->map.fd))
		ft_exit(cub, "Map problem");
}
