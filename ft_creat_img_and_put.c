/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_img_and_put.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:58:58 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/10 16:58:59 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		ft_put_data(t_fdf *fdf)
{
	fdf->start_x = (fdf->x_centr -
		(fdf->width_matrix / 6 * fdf->l_len) / 10);
	fdf->start_y = (fdf->y_centr -
		(fdf->height_matrix / 6 * fdf->l_len) / 10);
	ft_brezenhem(fdf);
	return (0);
}

int				ft_creat_img_and_put(t_fdf *fdf)
{
	int endian;

	ft_find_z(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	fdf->str_img = (int*)mlx_get_data_addr(fdf->img,
		&fdf->bpp, &fdf->s_line, &endian);
	ft_bzero(fdf->str_img, (size_t)fdf->win_width *
		(size_t)fdf->win_height * 4);
	ft_put_data(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	return (0);
}
