/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brezenhem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:51:22 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/21 15:56:41 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void		ft_put_pixel(t_fdf *fdf, int x, int y, t_color *col)
{
	int		width;

	width = fdf->s_line / (fdf->bpp / 8);
	col->color = ft_gradient(col->f_color, col->s_color, col->procent);
	if ((x >= 0 && y >= 0) && (x < fdf->win_width && y < fdf->win_height))
		fdf->str_img[width * y + x] = (int)col->color;
}

static	void		ft_calc(t_fdf *fdf, t_color *col, int color)
{
	fdf->brez.x = fdf->brez.x1;
	fdf->brez.y = fdf->brez.y1;
	fdf->brez.dx = abs(fdf->brez.x2 - fdf->brez.x1);
	fdf->brez.dy = abs(fdf->brez.y2 - fdf->brez.y1);
	fdf->brez.sx = fdf->brez.x1 < fdf->brez.x2 ? 1 : -1;
	fdf->brez.sy = fdf->brez.y1 < fdf->brez.y2 ? 1 : -1;
	if (fdf->brez.dy == 0)
		fdf->brez.error = 0;
	else
		fdf->brez.error = (fdf->brez.dx / fdf->brez.dy != 0 ?
			fdf->brez.dx : -(fdf->brez.dy)) / 2;
	if (col->f_color == -1)
		col->f_color = color;
	if (col->s_color == -1)
		col->s_color = color;
}

static	void		ft_drawline(t_fdf *fdf, t_color *col)
{
	ft_calc(fdf, col, fdf->color);
	col->color = col->f_color;
	while (fdf->brez.x != fdf->brez.x2 || fdf->brez.y != fdf->brez.y2)
	{
		col->procent = (fdf->brez.dx > fdf->brez.dy ?
			ft_procent(fdf->brez.x, fdf->brez.x1, fdf->brez.x2) :
			ft_procent(fdf->brez.y, fdf->brez.y1, fdf->brez.y2));
		ft_put_pixel(fdf, fdf->brez.x, fdf->brez.y, col);
		fdf->brez.e2 = fdf->brez.error;
		if (fdf->brez.e2 > -(fdf->brez.dx))
		{
			fdf->brez.error -= fdf->brez.dy;
			fdf->brez.x += fdf->brez.sx;
		}
		if (fdf->brez.e2 < fdf->brez.dy)
		{
			fdf->brez.error += fdf->brez.dx;
			fdf->brez.y += fdf->brez.sy;
		}
	}
}

static	void		ft_brezenhem_put_coord(t_fdf *fdf, size_t i, size_t j)
{
	t_color	col;

	col.f_color = fdf->matrix[i][j].color;
	if (j < fdf->width_matrix - 1)
	{
		fdf->brez.x2 = fdf->matrix[i][j + 1].x *
		fdf->l_len + fdf->start_x + fdf->go_x;
		fdf->brez.y2 = fdf->matrix[i][j + 1].y *
		fdf->l_len + fdf->start_y + fdf->go_y;
		col.s_color = fdf->matrix[i][j + 1].color;
		ft_drawline(fdf, &col);
	}
	if (fdf->matrix[i + 1] != NULL)
	{
		fdf->brez.x2 = fdf->matrix[i + 1][j].x *
		fdf->l_len + fdf->start_x + fdf->go_x;
		fdf->brez.y2 = fdf->matrix[i + 1][j].y *
		fdf->l_len + fdf->start_y + fdf->go_y;
		col.s_color = fdf->matrix[i + 1][j].color;
		ft_drawline(fdf, &col);
	}
}

void				ft_brezenhem(t_fdf *fdf)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (fdf->matrix[i] != NULL)
	{
		j = 0;
		while (j < fdf->width_matrix)
		{
			fdf->brez.x1 = fdf->matrix[i][j].x * fdf->l_len +
			fdf->start_x + fdf->go_x;
			fdf->brez.y1 = fdf->matrix[i][j].y * fdf->l_len +
			fdf->start_y + fdf->go_y;
			ft_brezenhem_put_coord(fdf, i, j);
			++j;
		}
		++i;
	}
}
