/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:18:11 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/11 16:18:13 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_new_struct(t_coord *new, int x, ssize_t y, char *z_color)
{
	new->x = (double)x;
	new->y = (double)y;
	new->z = (double)ft_atoi(z_color);
	while (*z_color != 'x' && *z_color != '\0')
		z_color++;
	if (*(++z_color) != '\0')
		new->color = ft_atoi_base(z_color, 16);
	else
		new->color = -1;
}
