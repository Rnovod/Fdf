/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:01:42 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/19 20:33:17 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void		ft_change_z(t_fdf *fdf, size_t i, size_t j)
{
	double		p_min_z;
	double		p_max_z;

	p_min_z = ft_procent(fdf->origin[i][j].z, fdf->min_z, 0);
	p_max_z = ft_procent(fdf->origin[i][j].z, 0, fdf->max_z);
	if (fdf->min_z != fdf->origin[i][j].z && fdf->origin[i][j].z < 0)
		fdf->matrix[i][j].color = ft_gradient(0xa52a2a, fdf->color, p_min_z);
	if (fdf->max_z != fdf->origin[i][j].z && fdf->origin[i][j].z > 0)
		fdf->matrix[i][j].color = ft_gradient(fdf->color, 0xFFFFFF, p_max_z);
}

static	void		ft_change_another_z(t_fdf *fdf)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (fdf->matrix[i] != NULL)
	{
		j = 0;
		while (j < fdf->width_matrix)
		{
			if (fdf->origin[i][j].color == -1 && fdf->origin[i][j].z != 0)
				ft_change_z(fdf, i, j);
			j++;
		}
		i++;
	}
}

static	void		ft_change_color_z(t_fdf *fdf)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (fdf->matrix[i] != NULL)
	{
		j = 0;
		while (j < fdf->width_matrix)
		{
			if (fdf->origin[i][j].color == -1)
			{
				if (fdf->min_z == fdf->origin[i][j].z &&
					fdf->origin[i][j].z != 0)
					fdf->matrix[i][j].color = 0xa52a2a;
				if (fdf->max_z == fdf->origin[i][j].z &&
					fdf->origin[i][j].z != 0)
					fdf->matrix[i][j].color = 0xFFFFFF;
			}
			j++;
		}
		i++;
	}
	ft_change_another_z(fdf);
}

void				ft_find_z(t_fdf *fdf)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (fdf->matrix[i] != NULL)
	{
		j = 0;
		while (j < fdf->width_matrix)
		{
			if (fdf->min_z > fdf->origin[i][j].z &&
				fdf->origin[i][j].color != 0)
				fdf->min_z = fdf->origin[i][j].z;
			if (fdf->max_z < fdf->origin[i][j].z &&
				fdf->origin[i][j].color != 0)
				fdf->max_z = fdf->origin[i][j].z;
			j++;
		}
		i++;
	}
	ft_change_color_z(fdf);
}
