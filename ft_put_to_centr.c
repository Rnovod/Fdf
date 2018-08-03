/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_to_centr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:41:15 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/16 16:41:16 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_put_to_centr(t_fdf *fdf)
{
	fdf->go_x = 0;
	fdf->go_y = 0;
}

void			ft_discard_to_default(t_fdf *fdf)
{
	size_t i;
	size_t j;

	ft_put_to_centr(fdf);
	fdf->rot_x = 0;
	fdf->rot_y = 0;
	fdf->rot_z = 0;
	if (fdf->win_width == 1700 && fdf->win_height == 1300)
		fdf->l_len = 1;
	else
		fdf->l_len = 10;
	i = 0;
	while (fdf->matrix[i] != NULL)
	{
		j = 0;
		while (j < fdf->width_matrix)
		{
			fdf->matrix[i][j].x = fdf->origin[i][j].x;
			fdf->matrix[i][j].y = fdf->origin[i][j].y;
			fdf->matrix[i][j].z = fdf->origin[i][j].z;
			j++;
		}
		++i;
	}
}
