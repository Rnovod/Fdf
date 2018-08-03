/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:25:40 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/13 13:25:41 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void		ft_rot_x(t_fdf *fdf, t_coord *new, size_t i, size_t j)
{
	double		rad;

	rad = (fdf->rot_x * PI / 180);
	new->y = (fdf->origin[i][j].y * cos(rad) + (fdf->origin[i][j].z
		* fdf->ch_z) * sin(rad));
	new->z = (fdf->origin[i][j].y * -sin(rad) + (fdf->origin[i][j].z
		* fdf->ch_z) * cos(rad));
}

static	void		ft_rot_y(t_fdf *fdf, t_coord *new, size_t i, size_t j)
{
	double		rad;

	rad = (fdf->rot_y * PI / 180);
	new->x = (fdf->origin[i][j].x * cos(rad) + new->z * sin(rad));
	new->z = (fdf->origin[i][j].x * -sin(rad) + new->z * cos(rad));
}

static	void		ft_rot_z(t_fdf *fdf, t_coord *new, size_t i, size_t j)
{
	double		rad;

	rad = (fdf->rot_z * PI / 180);
	fdf->matrix[i][j].x = (new->x * cos(rad) + new->y * sin(rad));
	fdf->matrix[i][j].y = (new->x * -sin(rad) + new->y * cos(rad));
}

static	void		ft_rot_xyz(t_fdf *fdf)
{
	size_t		i;
	size_t		j;
	t_coord		new;

	i = 0;
	while (fdf->matrix[i] != NULL)
	{
		j = 0;
		while (j < fdf->width_matrix)
		{
			ft_rot_x(fdf, &new, i, j);
			fdf->matrix[i][j].y = new.y;
			fdf->matrix[i][j].z = new.z;
			ft_rot_y(fdf, &new, i, j);
			fdf->matrix[i][j].x = new.x;
			fdf->matrix[i][j].z = new.z;
			ft_rot_z(fdf, &new, i, j);
			j++;
		}
		i++;
	}
}

void				ft_rot_and_z(t_fdf *fdf, int key)
{
	if (key == 13)
		fdf->rot_x -= 1;
	if (key == 1)
		fdf->rot_x += 1;
	if (key == 0)
		fdf->rot_y -= 1;
	if (key == 2)
		fdf->rot_y += 1;
	if (key == 12)
		fdf->rot_z -= 1;
	if (key == 14)
		fdf->rot_z += 1;
	if (key == 24)
		fdf->ch_z += 0.05;
	if (key == 27)
		fdf->ch_z -= 0.05;
	ft_rot_xyz(fdf);
}
