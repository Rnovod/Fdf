/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:46:41 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/09 12:46:42 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		ft_key(int key, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf*)param;
	if (key == 53)
	{
		ft_free_all(fdf);
		ft_putendl("Exiting.");
		exit(1);
	}
	if (key >= 123 && key <= 126)
		ft_go(fdf, key);
	if ((key >= 18 && key <= 23) || key == 25 ||
		key == 26 || key == 28 || key == 29)
		ft_change_color(fdf, key);
	if (key == 36)
		ft_put_to_centr(fdf);
	if (key == 13 || key == 1 || key == 0 || key == 2 ||
		key == 12 || key == 14 || key == 24 || key == 27)
		ft_rot_and_z(fdf, key);
	if (key == 49)
		ft_discard_to_default(fdf);
	ft_creat_img_and_put(fdf);
	return (0);
}

static	int		ft_exit(t_fdf *fdf)
{
	ft_free_all(fdf);
	ft_putendl("Exiting.");
	exit(1);
}

static	int		ft_mouse(int button, int x, int y, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf*)param;
	(void)x;
	(void)y;
	if (button == 4)
		fdf->l_len += 1;
	if (button == 5)
		if (fdf->l_len > 1)
			fdf->l_len -= 1;
	ft_creat_img_and_put(fdf);
	return (0);
}

int				ft_fdf(t_fdf *fdf)
{
	ft_rot_and_z(fdf, -1);
	ft_creat_img_and_put(fdf);
	mlx_hook(fdf->win, 2, 5, &ft_key, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, ft_exit, fdf);
	mlx_mouse_hook(fdf->win, &ft_mouse, fdf);
	return (0);
}
