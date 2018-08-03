/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:04:58 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/16 16:05:05 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void			ft_calc_width_height_len(t_fdf *fdf)
{
	fdf->win_width = fdf->width_matrix * 35;
	fdf->win_height = fdf->height_matrix * 40;
	if (fdf->win_width > 1700)
		fdf->win_width = 1700;
	if (fdf->win_height > 1300)
		fdf->win_height = 1300;
	if (fdf->win_width == 1700 && fdf->win_height == 1300)
		fdf->l_len = 1;
	else
		fdf->l_len = 10;
}

int						ft_info(t_fdf *fdf)
{
	if (fdf->win_width == 0 && fdf->win_height == 0)
		ft_calc_width_height_len(fdf);
	fdf->x_centr = fdf->win_width / 2;
	fdf->y_centr = fdf->win_height / 2;
	fdf->color = 0xFFFFFF;
	fdf->rot_x = 0;
	fdf->rot_y = 0;
	fdf->rot_z = 0;
	fdf->go_x = 0;
	fdf->go_y = 0;
	fdf->ch_z = 1;
	fdf->min_z = 0;
	fdf->max_z = 0;
	if (!(fdf->mlx = mlx_init()))
		return (-1);
	if (!(fdf->win = mlx_new_window(fdf->mlx, fdf->win_width,
	fdf->win_height, "rnovodra_and_FDF")))
		return (-1);
	if (!(fdf->img = mlx_new_image(fdf->mlx, fdf->win_width, fdf->win_height)))
		return (-1);
	return (0);
}
