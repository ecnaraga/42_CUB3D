/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:41:27 by galambey          #+#    #+#             */
/*   Updated: 2024/05/01 11:45:49 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	ft_equald(double to_check, double to_cmp)
{
	if (to_check > to_cmp - 0.01 && to_check < to_cmp + 0.01)
		return (TRUE);
	return (FALSE);
}

double	ft_abs_gap(double a, double b)
{
	if (a > b)
		return (a - b);
	return (b - a);
}

int	ft_sign(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (0);
	return (1);
}

double	ft_deg_to_rad(double a)
{
	return ((a * PI) / 180);
}
