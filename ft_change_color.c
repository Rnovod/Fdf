/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:04:41 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/15 14:04:42 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_change_color(t_fdf *fdf, int key)
{
	if (key == 18)
		fdf->color = 0xFFFFFF;
	else if (key == 19)
		fdf->color = 0xff;
	else if (key == 20)
		fdf->color = 0xff00;
	else if (key == 21)
		fdf->color = 0xff0000;
	else if (key == 23)
		fdf->color = 0xcdcd;
	else if (key == 22)
		fdf->color = 0xffd700;
	else if (key == 26)
		fdf->color = 0xff7f00;
	else if (key == 28)
		fdf->color = 0xa020f0;
	else if (key == 25)
		fdf->color = 0x0;
	else if (key == 29 && fdf->put_color == -1)
		fdf->color = 0x2f4f4f;
	else if (key == 29 && fdf->put_color != -1)
		fdf->color = fdf->put_color;
}
