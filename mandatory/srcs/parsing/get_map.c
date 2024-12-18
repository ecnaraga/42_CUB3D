/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 01:46:19 by athiebau          #+#    #+#             */
/*   Updated: 2024/05/15 17:12:53 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_char_bis(char *str, int *i, int *player)
{
	if (str[*i] == 'N' || str[*i] == 'S' || str[*i] == 'E' || str[*i] == 'W')
		*player += 1;
	if (str[*i] == '\n')
		str[*i] = 'R';
}

char	*check_char(char *str, t_cub *cub)
{
	int	i;
	int	player;

	i = -1;
	player = 0;
	while (str[++i] == '\n')
		str[i] = 'R';
	if (i == -1)
		i = 0;
	while (str[i])
	{
		check_char_bis(str, &i, &player);
		if (!ft_strchr(ALLOWD_CHAR, str[i]))
			return (ft_exit(cub, "Character not allowed detected"), NULL);
		i++;
	}
	if (player != 1)
		return (ft_exit(cub, "Too many or no player"), NULL);
	if (str[ft_strlen(str) - 1] == 'R')
		return (ft_exit(cub, "Empty line at the end"), NULL);
	while (--i >= 0)
		if (i > 0 && str[i] == 'R' && str[i - 1] == 'R')
			return (ft_exit(cub, "Empty line"), NULL);
	return (str);
}

char	*get_next_line_bis(int fd, t_cub *cub)
{
	char	*buffer;
	char	*str;
	int		flag;

	flag = 0;
	str = mcgic(NULL, sizeof(char) * 1, MLC);
	if (!str)
		return (NULL);
	str[0] = '\0';
	buffer = get_next_line(fd);
	if (!buffer)
		ft_exit(cub, "No map");
	while (buffer)
	{
		if (flag == 0 && ck_char(buffer, '1'))
			flag = 1;
		str = mcgic(ft_strjoin(str, buffer), 0, ADD);
		if (!str)
			return (NULL);
		free(buffer);
		buffer = get_next_line(fd);
	}
	if (flag == 0)
		ft_exit(cub, "No map");
	return (str);
}

bool	get_map(t_cub *cub, int fd)
{
	char	*str;

	str = get_next_line_bis(fd, cub);
	close(cub->map.fd);
	if (!str)
		return (ft_exit(cub, "Problem encoutered while reading map"), false);
	str = check_char(str, cub);
	if (!str)
		return (false);
	cub->map.map_final = ft_split_mcgic(str, 'R');
	if (!cub->map.map_final)
		return (ft_exit(cub, "Allocation failed"), false);
	cub->map.map_final = check_limits(cub);
	if (!cub->map.map_final)
		return (false);
	return (true);
}
