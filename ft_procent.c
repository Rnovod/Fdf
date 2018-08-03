/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 18:10:21 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/19 18:10:23 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double				ft_procent(double color, double f_color, double s_color)
{
	if (color == f_color)
		return (0.0);
	if (color == s_color)
		return (1.0);
	return ((color - f_color) / (s_color - f_color));
}
