/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:29:33 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/18 20:29:34 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void		ft_free_matrix(t_fdf *fdf)
{
	size_t	i;

	i = 0;
	while (fdf->matrix[i] != NULL)
	{
		free(fdf->matrix[i]);
		free(fdf->origin[i]);
		i++;
	}
	free(fdf->matrix);
	free(fdf->origin);
}

void				ft_free_all(t_fdf *fdf)
{
	ft_free_matrix(fdf);
}
