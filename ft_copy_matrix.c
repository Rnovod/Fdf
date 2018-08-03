/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:53:43 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/15 19:53:44 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_copy_matrix(t_fdf *fdf)
{
	size_t		i;
	size_t		j;

	if (!(fdf->origin = (t_coord**)malloc(sizeof(t_coord*)
		* (fdf->height_matrix + 1))))
		return (ft_error(ENOMEM));
	i = 0;
	while (fdf->matrix[i] != NULL)
	{
		j = 0;
		if (!(fdf->origin[i] = (t_coord*)malloc(sizeof(t_coord)
			* fdf->width_matrix)))
			return (ft_error(ENOMEM));
		while (j < fdf->width_matrix)
		{
			fdf->origin[i][j].x = fdf->matrix[i][j].x - fdf->width_matrix / 2;
			fdf->origin[i][j].y = fdf->matrix[i][j].y - fdf->height_matrix / 2;
			fdf->origin[i][j].z = fdf->matrix[i][j].z;
			fdf->origin[i][j].color = fdf->matrix[i][j].color;
			j++;
		}
		i++;
	}
	return (0);
}
