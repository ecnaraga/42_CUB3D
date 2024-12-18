/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 05:59:01 by athiebau          #+#    #+#             */
/*   Updated: 2024/05/17 02:14:49 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_max_len(char **str)
{
	int	len;
	int	tmp;
	int	i;

	i = 0;
	len = ft_strlen(str[i]);
	while (str[++i])
	{
		tmp = ft_strlen(str[i]);
		if (len < tmp)
			len = tmp;
	}
	return (len);
}

static char	*ft_strcpy_bis(char *dst, const char *src, int len)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < (size_t)(len))
		dst[i++] = ' ';
	dst[i] = '\0';
	return (dst);
}

char	**check_limits(t_cub *cub)
{
	int		len;
	int		i;
	char	*tmp;

	i = -1;
	len = get_max_len(cub->map.map_final);
	while (cub->map.map_final[++i])
	{
		if (ft_strlen(cub->map.map_final[i]) < (size_t)len)
		{
			tmp = cub->map.map_final[i];
			cub->map.map_final[i] = mcgic(NULL, (len + 1), MLC);
			if (!cub->map.map_final[i])
				return (NULL);
			cub->map.map_final[i] = ft_strcpy_bis(cub->map.map_final[i], tmp,
					len);
			mcgic(tmp, 0, FREE);
		}
	}
	if (!check_borders(cub, len, i, -1))
		return (NULL);
	cub->map.map_height = i - 1;
	cub->map.map_width = len;
	return (cub->map.map_final);
}
